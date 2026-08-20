# Bank System 🏦

A console-based **Bank Management System** written in **C++** using Object-Oriented Programming principles. This is a learning project built to practice OOP concepts such as inheritance, encapsulation, file handling, and role-based access control.

> ⚠️ **Educational project** — data is stored in plain text files and PINs are not encrypted. This is **not** meant for production or real financial use. See [Known Limitations](#known-limitations--roadmap) below for planned improvements.

## Features

### 👤 Client Management
- List all clients
- Add a new client
- Update client information
- Delete a client
- Find a client by account number

### 💰 Transactions
- Deposit
- Withdraw
- Transfer between accounts (with transfer log)
- Show total balances of all clients

### 🔐 User & Access Management
- Login / Logout system with a limited number of trials (3 attempts before lockout)
- Add / update / delete system users
- List users and find a specific user
- Role-based permissions (bitwise flags) — each user can be granted a combination of:
  - List Clients
  - Add New Client
  - Delete Client
  - Update Clients
  - Find Client
  - Transactions
  - Manage Users
  - Show Login/Register Log
  - Full Access (`eAll`)
- Login/Register history log

## Project Structure

```
Bank-System/
├── Bank.sln                     # Visual Studio solution file
└── Bank/
    ├── Bank.cpp                 # Entry point
    ├── Global.h                 # Global current-user state
    │
    ├── clsPerson.h               # Base class for Client & User
    ├── clsBankClient.h           # Client model + file persistence
    ├── clsUser.h                 # User model + permissions + file persistence
    │
    ├── clsScreen.h                # Base class for all screens
    ├── clsMainScreen.h            # Main menu
    ├── clsLoginScreen.h           # Login screen
    ├── clsLoginRegisterScreen.h   # Login history screen
    ├── clsClientListScreen.h      # List clients
    ├── clsAddClientScreen.h       # Add client
    ├── clsUpdateClientScreen.h    # Update client
    ├── clsDeleteClientScreen.h    # Delete client
    ├── clsFindClientScreen.h      # Find client
    ├── clsDepositScreen.h         # Deposit
    ├── clsWithdrawScreen.h        # Withdraw
    ├── clsTransferScreen.h        # Transfer funds
    ├── clsTransferLogScreen.h     # Transfer history
    ├── clsTransactionsScreen.h    # Transactions menu
    ├── clsTotalBalancesScreen.h   # Total balances report
    ├── clsManageUsers.h           # Manage users menu
    ├── clsAddNewUserScreen.h      # Add user
    ├── clsUpdateUserScreen.h      # Update user
    ├── clsDeleteUserScreen.h      # Delete user
    ├── clsFindUserScreen.h        # Find user
    ├── clsListUsersScreen.h       # List users
    │
    ├── clsString.h                # String helper utilities
    ├── clsDate.h                  # Date/time helper utilities
    ├── clsUtil.h                  # General utilities
    ├── clsInputValidate.h         # Input validation helpers
    │
    ├── Clients.txt                 # Client data storage
    ├── Users.txt                   # User data storage
    ├── LoginRegister.txt           # Login history storage
    └── TransferLog.txt             # Transfer history storage
```

## Getting Started

### Prerequisites
- Windows OS
- Visual Studio (2019 or later recommended) with the **Desktop development with C++** workload installed

### Running the Project
1. Clone the repository:
   ```bash
   git clone https://github.com/mohamed10sherif/Bank-System.git
   ```
2. Open `Bank.sln` in Visual Studio.
3. Build the solution (`Ctrl+Shift+B`).
4. Run the project (`F5` or `Ctrl+F5`).

### Data Files
On first run, the program reads/writes to the `.txt` files in the `Bank/` folder (`Clients.txt`, `Users.txt`, `LoginRegister.txt`, `TransferLog.txt`). These act as a simple flat-file database, with each field separated by `#//#`.

## How It Works

- The app starts at the **Login Screen**. You have 3 attempts to enter a valid username/password before being locked out for that session.
- Once logged in, the **Main Menu** shows options based on the current user's permissions.
- Each entity (`Client`, `User`) is loaded from its `.txt` file into memory as a list of objects, modified, and the whole file is rewritten on save.

## Known Limitations & Roadmap

This project is a great starting point for learning OOP, but the following areas are intentionally left for further improvement as learning exercises:

- [ ] **Move from `.txt` files to a real database** (e.g., SQLite or SQL Server) for reliability and to avoid data corruption from malformed lines.
- [ ] **Hash PINs/passwords** instead of storing them as plain text.
- [ ] **Stop logging plaintext passwords** in `LoginRegister.txt` — log only the outcome (success/failure).
- [ ] **Separate business logic from console I/O** so the core logic (`clsBankClient`, `clsUser`) can eventually support other interfaces (GUI, API) without rewriting everything.
- [ ] **Add stronger validation** on financial operations (e.g., transfer/withdraw limits, negative balance protection).
- [ ] **Add unit tests** for core classes.
- [ ] **Cross-platform support** — currently relies on Windows-only calls like `system("cls")` and `system("pause>0")`.

## Author

**Mohamed Sherif** — [github.com/mohamed10sherif](https://github.com/mohamed10sherif)

## License

No license specified yet. Consider adding one (e.g., [MIT License](https://choosealicense.com/licenses/mit/)) if you'd like others to freely use or contribute to this project.
