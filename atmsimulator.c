// A C program that simulates an ATM
#include <stdio.h>

// Global variables to store the account information
int account = 15987;
int pin = 1234; // The pin number
double balance = 10000.0; // The account balance
char history[1000] = ""; // The transaction history

// A function to check the balance
void check_balance()
{
    printf("Your current balance is %.2f\n", balance);
    sprintf(history, "%s\nChecked balance: %.2f", history, balance); // Update the history
}

// A function to withdraw money
void withdraw()
{
    double amount; // The amount to withdraw
    printf("Enter the amount to withdraw: ");
    scanf("%lf", &amount);
    if (amount > 0 && amount <= balance) // Check if the amount is valid
    {
        balance -= amount; // Deduct the amount from the balance
        printf("You have withdrawn %.2f\n", amount);
        printf("Your new balance is %.2f\n", balance);
        sprintf(history, "%s\nWithdrew: %.2f", history, amount); // Update the history
    }
    else // Invalid amount
    {
        printf("Invalid amount. Please try again.\n");
    }
}

// A function to deposit money
void deposit()
{
    double amount; // The amount to deposit
    printf("Enter the amount to deposit: ");
    scanf("%lf", &amount);
    if (amount > 0) // Check if the amount is valid
    {
        balance += amount; // Add the amount to the balance
        printf("You have deposited %.2f\n", amount);
        printf("Your new balance is %.2f\n", balance);
        sprintf(history, "%s\nDeposited: %.2f", history, amount); // Update the history
    }
    else // Invalid amount
    {
        printf("Invalid amount. Please try again.\n");
    }
}

// A function to transfer money
void transfer()
{
    int account = 15987 ; // The account number to transfer to
    double amount; // The amount to transfer
    printf("Enter the account number to transfer to: ");
    scanf("%d", & account);
    printf("Enter the amount to transfer: ");
    scanf("%lf", &amount);
    if (amount > 0 && amount <= balance) // Check if the amount is valid
    {
        balance -= amount; // Deduct the amount from the balance
        printf("You have transferred %.2f to account %d\n", amount, account);
        printf("Your new balance is %.2f\n", balance);
        sprintf(history, "%s\nTransferred: %.2f to account %d", history, amount, account); // Update the history
    }
    else // Invalid amount
    {
        printf("Invalid amount. Please try again.\n");
    }
}

// A function to show the transaction history
void show_history()
{
    printf("Your transaction history is:\n%s\n", history);
}

// The main function
int main()
{
    int user_pin; // The user's pin
    int choice; // The user's choice
    int flag = 0; // A flag to indicate if the pin is correct
    printf("Welcome to the ATM\n");
    printf("Please enter your pin: ");
    scanf("%d", &user_pin);
    if (user_pin == pin) // Check if the pin is correct
    {
        flag = 1; // Set the flag to 1
        printf("Pin accepted\n");
    }
    else // Wrong pin
    {
        printf("Wrong pin. Please try again.\n");
    }
    while (flag) // Loop until the flag is 0
    {
        printf("Please choose an option:\n");
        printf("1. Check balance\n");
        printf("2. Withdraw\n");
        printf("3. Deposit\n");
        printf("4. Transfer\n");
        printf("5. Show history\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        switch (choice) // Switch based on the choice
        {
        case 1:
            check_balance();
            break;
        case 2:
            withdraw();
            break;
        case 3:
            deposit();
            break;
        case 4:
            transfer();
            break;
        case 5:
            show_history();
            break;
        case 6:
            flag = 0; // Set the flag to 0 to exit the loop
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
    printf("Thank you for using the ATM\n");
    return 0;
}
