**RedBox Cinema Seat Booking System**
**Project Title**
RedBox Cinema Seat Booking System

**Problem Statement**
This project is a console-based cinema seat booking system made in C++. The goal is to simulate how a cinema allows customers to book seats.

**Users can:**
-See which seats are available.
-Choose and book seats.
-Check the price for each seat based on its type (Premium, Gold, or Regular).

The system also prevents double-booking, so no two users can book the same seat. This project helps me to learn Object-Oriented Programming (OOP), working with dynamic arrays, input validation and basic logic for pricing.

**OOP Concepts Used**
**Classes & Objects:** Two main classes, Cinema and Booking, separate responsibilities and make the code organized.
**Encapsulation: **Seat data is private and accessed only through class methods.
**Constructors & Destructors:** Used to create and delete the seating chart in memory.
**Polymorphism:** Design allows for future extensions, such as different booking methods.
**Inheritance:** Can be extended later to add VIP seats, special users, or multiple cinema halls.

**Classes**
**-Cinema**
-Represents the cinema hall and manages all the seats.
-Uses a 2D array where each seat is marked as available (#) or booked (*).
-Determines seat type based on the row:
     -Row 1 → Premium
     -Row 2–8 → Gold
     -Row 9–15 → Regular
-Provides functions to:
     -Show the seating chart.
     -Check if a seat is available.
     -Mark a seat as booked.
**-Booking**
     -Handles the ticket booking process.
     -Lets the user choose how many tickets to buy.
     -Checks if the selected seat is available.
     -Books the seat if it is free and shows the price.
     -Allows the user to reselect a seat if it is already booked.
     -Updates the cinema’s seating chart after each booking.

**Seat Categories and Pricing**
**Premium Seats:** Row 1 only. Price per seat is $30.
**Gold Seats:** Rows 2 to 8. Price per seat is $20.
**Regular Seats:** Rows 9 to 15. Price per seat is $15.

**Legend:**
# = Available
* = Booked
This allows users to choose seats based on budget and preference.

**System Workflow**
1-Initialize the cinema hall and mark all seats as available.
2-Display the seating chart to the user.
3-Show seat pricing information.
4-Ask the user how many tickets they want.

**For each ticket:**
Ask the user to select row and column.
Check if the seat is available.
If yes, book the seat and show the price.
If no, let the user choose another seat.
Update and display the seating chart after all bookings.

**How to Run**
**-Compile the program using a C++ compiler:**
g++ main.cpp -o RedBoxCinema
**- & Run the executable:**
./RedBoxCinema
