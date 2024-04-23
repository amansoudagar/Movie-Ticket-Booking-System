#include <stdio.h>

#define MAX_MOVIES 5
#define MAX_TIME_SLOTS 3
#define MAX_THEATERS 2

#define ROWS 10
#define SEATS 10

int seats[ROWS][SEATS];

// Function to display the seating layout
void displayLayout() {
    printf("Seating Layout:\n");
    printf("-------------SCREEN------------\n");
    printf("   1  2  3  4  5  6  7  8  9 10\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < SEATS; j++) {
            if (seats[i][j] != 0)
                printf("[X]"); // Booked seat
            else
                printf("[ ]"); // Available seat
        }
        printf("\n");
    }
    printf("--------------------------------\n");
}

// Function to book a seat
void bookSeat(int row, int seat) {
    if (row >= 0 && row < ROWS && seat >= 0 && seat < SEATS) {
        if (seats[row][seat] == 0) {
            seats[row][seat] = 1;
            printf("Seat %c%d booked successfully.\n", 'A' + row, seat + 1);
        } else {
            printf("Seat %c%d is already booked.\n", 'A' + row, seat + 1);
        }
    } else {
        printf("Invalid seat selection.\n");
    }
}

int main() {
    // Array to store the movies
    char movies[MAX_MOVIES][50] = {
        "Avengers: Endgame",
        "The Dark Knight",
        "Inception",
        "Pulp Fiction",
        "Fight Club"
    };

    // Array to store the time slots
    char timeSlots[MAX_TIME_SLOTS][10] = {
        "10:00 AM",
        "02:00 PM",
        "06:00 PM"
    };

    // Array to store the theaters
    char theaters[MAX_THEATERS][20] = {
        "INOX",
        "PVR"
    };

    int movieChoice, timeSlotChoice, theaterChoice;

    // Display the available movies
    printf("Available Movies:\n");
    for (int i = 0; i < MAX_MOVIES; i++) {
        printf("%d. %s\n", i + 1, movies[i]);
    }

    // Get the user's movie choice
    printf("Enter the movie number: ");
    scanf("%d", &movieChoice);

    // Display the available time slots
    printf("Available Time Slots:\n");
    for (int i = 0; i < MAX_TIME_SLOTS; i++) {
        printf("%d. %s\n", i + 1, timeSlots[i]);
    }

    // Get the user's time slot choice
    printf("Enter the time slot number: ");
    scanf("%d", &timeSlotChoice);

    // Display the available theaters
    printf("Available Theaters:\n");
    for (int i = 0; i < MAX_THEATERS; i++) {
        printf("%d. %s\n", i + 1, theaters[i]);
    }

    // Get the user's theater choice
    printf("Enter the theater number: ");
    scanf("%d", &theaterChoice);

    // Initialize all seats as available
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < SEATS; j++) {
            seats[i][j] = 0; // Initialize as available
        }
    }

    while (1) {
        displayLayout();

        printf("\nMenu:\n");
        printf("1. Book a seat\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the row (A-J): ");
                scanf(" %c", &choice);
                choice = toupper(choice);
                int row = choice - 'A';

                printf("Enter the seat number (1-10): ");
                int seat;
                scanf("%d", &seat);
                seat--;

                bookSeat(row, seat);
                break;
            case '2':
                printf("Thank you for using the ticket booking system.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}