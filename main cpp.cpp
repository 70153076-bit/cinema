#include <iostream>
using namespace std;

class Cinema 
{
private:
    int rows;
    int cols;
    char **seats;

public:
    Cinema(int r=15, int c=30) 
    {
        rows=r;
        cols=c;
        seats=new char*[rows];
        for(int i=0; i<rows; i++) 
        {
            seats[i]=new char[cols];
            for(int j=0; j<cols; j++) 
            {
                seats[i][j]='#';
            }
        }
    }

    void displayChart() 
    {
        cout<<"\t";
        for (int j=0; j<cols; j++) 
        {
            if(j<9)
                cout<<j+1<<"  ";
            else
                cout<<j+1<<" ";
        }
        cout<<endl;

        for (int i=0; i<rows; i++) 
        {
            if(i<9)
                cout<<"Row "<<i+1<<":  ";
            else
                cout<<"Row "<<i+1<<": ";
            for (int j=0; j<cols; j++) 
            {
                cout<<seats[i][j]<<"  ";
            }
            cout<<endl;
        }
    }

    bool checkAvailability(int row, int col) 
    {
        if(row>=1 && row<=rows && col>=1 && col<=cols) 
        {
            return seats[row-1][col-1]=='#';
        }
        return false;
    }

    void updateSeat(int row, int col) 
    {
        if (checkAvailability(row, col)) 
        {
            seats[row-1][col-1]='*';
        }
    }

    char getSeatType(int row) 
    {
        if(row==1)
            return 'P'; 
        else if(row>=2 && row<=8)
            return 'G'; 
        else
            return 'R'; 
    }

    ~Cinema() 
    {
        for (int i=0; i<rows; i++)
            delete[] seats[i];
        delete[] seats;
    }
};

class Booking 
{
private:
    Cinema &cinema;
    int numSeats;

public:
    Booking(Cinema &c) : cinema(c) 
    {
        numSeats = 0;
    }

    void startBooking() 
    {
        cout<<"Enter number of tickets you want to purchase: ";
        cin>>numSeats;

        for (int i = 0; i < numSeats; i++) 
        {
            int row, col;
            cout<<"Select seat "<<i+1<<"(Row Column): ";
            cin>>row>>col;

            if (cinema.checkAvailability(row, col)) 
            {
                cinema.updateSeat(row, col);
                char type=cinema.getSeatType(row);
                int price=(type=='P')?30 : (type=='G')?20 : 15;
                cout<<"Seat booked! Price: $"<<price<<endl;
            } 
            else 
            {
                cout<<"Seat not available! Choose another seat."<<endl;
                i--; 
            }
        }
    }
};

int main() 
{
    system("color 04");
    cout<<"\t\t\t\t\t WELCOME TO REDBOX CINEMAS!!"<<endl<<endl;

    Cinema cinema;
    cinema.displayChart();

    cout<<"\nSEAT PRICING:"<<endl;
    cout<<"PREMIUM: \n\tRow 1 only \n\t$30 per seat"<<endl;
    cout<<"GOLD: \n\tRow 2 - Row 8 \n\t$20 per seat"<<endl;
    cout<<"REGULAR: \n\tRow 9 - Row 15 \n\t$15 per seat"<<endl<<endl;

    Booking booking(cinema);
    booking.startBooking();

    cout<<"\nUpdated Seating Chart:"<<endl;
    cinema.displayChart();

    return 0;
}
