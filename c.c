#include <stdio.h>
#include <stdbool.h>

#define ROWS 10
#define SEATS 10

bool seats[ROWS][SEATS];

// Function to display the seating layout
void displayLayout() {
    printf("Seating Layout:\n");
    printf("--------------------------------\n");
    printf("   1  2  3  4  5  6  7  8  9 10\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < SEATS; j++) {
            if (seats[i][j])
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
        if (!seats[row][seat]) {
            seats[row][seat] = true;
            printf("Seat %c%d booked successfully.\n", 'A' + row, seat + 1);
        } else {
            printf("Seat %c%d is already booked.\n", 'A' + row, seat + 1);
        }
    } else {
        printf("Invalid seat selection.\n");
    }
}

int main() {
    char choice;
    int row, seat;

    // Initialize all seats as available
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < SEATS; j++) {
            seats[i][j] = false;
        }
    }

    while (true) {
        displayLayout();

        printf("\nMenu:\n");
        printf("1. Book a seat\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the row (A-J): ");
                scanf(" %c", &choice);
                choice=toupper(choice);
                row = choice - 'A';

                printf("Enter the seat number (1-10): ");
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