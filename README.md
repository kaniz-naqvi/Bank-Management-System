# Bank Management System

A simple Bank Management System implemented in C++ that allows users to create accounts, log in, deposit/withdraw funds, change PIN, and reset their PIN. The system supports basic operations typically available in a banking system.

## Features
- **Create Account**: Users can create a new account by providing their name and setting a secure PIN. Each new account is assigned a unique account number.
- **Login**: Users can securely log into their account by providing their account number and PIN.
- **Deposit Funds**: Users can deposit money into their account, with the system ensuring the deposit amount is valid and greater than zero.
- **Withdraw Funds**: Users can withdraw money from their account, provided they have sufficient balance. The system checks if the withdrawal amount is valid and does not exceed the available balance.
- **View Balance**: Users can check their current account balance after logging in, providing them with real-time information about their funds.
- **Change PIN**: After logging in, users can change their PIN to a new one for security purposes.
- **Reset PIN**: In case the user forgets their PIN, they can reset it by verifying their account number and account holder name. After successful verification, the user can set a new PIN.

## How It Works
1. **Create an Account**: The user provides their name and sets a PIN. A unique account number is automatically assigned.
2. **Login**: The user enters their account number and PIN. If the credentials are correct, they can proceed to manage their account.
3. **Manage Account**: Once logged in, the user can choose to deposit or withdraw money, check their balance, or change their PIN.
4. **Reset PIN**: If the user forgets their PIN, they can provide their account number and name to verify their identity and reset their PIN.

This system implements these features to simulate basic banking operations and help users manage their accounts efficiently.

