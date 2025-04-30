#include <stdio.h>
#include <string.h>

#define MAX 10  // Maximum parking slots

char parkingLot[MAX][20];  // Array to store vehicle numbers
int front = -1, rear = -1;

// Function to add a vehicle
void addVehicle() {
    if (rear == MAX - 1) {
        printf("Parking lot is full!\n");
        return;
    }
    char vehicle[20];
    printf("Enter vehicle number: ");
    scanf("%s", vehicle);
    rear++;
    strcpy(parkingLot[rear], vehicle);
    if (front == -1) front = 0;
    printf("Vehicle %s parked at slot %d\n", vehicle, rear + 1);
}

// Function to remove a vehicle (FIFO style)
void removeVehicle() {
    if (front == -1 || front > rear) {
        printf("Parking lot is empty!\n");
        return;
    }
    printf("Vehicle %s removed from slot %d\n", parkingLot[front], front + 1);
    front++;
    if (front > rear) front = rear = -1;  // Reset if empty
}

// Function to check available space
void checkSpace() {
    int used = (front == -1) ? 0 : (rear - front + 1);
    printf("Total slots: %d\n", MAX);
    printf("Occupied slots: %d\n", used);
    printf("Available slots: %d\n", MAX - used);
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\n--- Parking Lot Management ---\n");
        printf("1. Add Vehicle\n2. Remove Vehicle\n3. Check Space\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addVehicle(); break;
            case 2: removeVehicle(); break;
            case 3: checkSpace(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}