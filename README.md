# Online Voting System

## Description
A console-based application developed in C++ that allows users to securely cast votes for candidates and automatically calculates the winner. This system simulates a real-world voting environment with user validation and results processing.

## Features
* **User Authentication:** Secure login system requiring a valid ID or credentials to vote.
* **Vote Casting:** Intuitive menu-driven interface for selecting candidates.
* **Input Validation:** Prevents invalid votes or multiple votes from the same user.
* **Result Calculation:** Automatically tallies votes and displays the winner and vote counts.
* **Data Persistence:** Saves voting data and results to text files (e.g., `votes.txt`) to ensure data is not lost after the program closes.

## Technology Stack
* **Language:** C++
* **Tools:** Visual Studio Code, Git, Standard Template Library (STL)

## How to Run
1.  **Clone the repository** to your local machine:
    ```bash
    git clone https://github.com/zoghby-ctrl/Online-Voting-System-Program.git
    ```
2.  **Navigate** to the project directory.
3.  **Compile the code** using a C++ compiler (like g++):
    ```bash
    g++ main.cpp -o app
    ```
4.  **Run the executable**:
    * On Windows:
        ```bash
        app.exe
        ```
    * On Linux/Mac:
        ```bash
        ./app
        ```
## Screenshots
![Program Preview](preview.png)
![Program Preview](preview.png (2))

## Future Improvements
* Implement a Graphical User Interface (GUI).
* Add encryption for the `votes.txt` file for better security.

## Author
* **Zoghby** - [zoghby-ctrl](https://github.com/zoghby-ctrl)

## Team
* **Ahmed Eloghby** – Team Lead
* **Abdelrahman Ali** – Team Member
* **Nouran Hossam** – Team Member
* **Ahmed Hassan** – Team Member
* **Bassant Ibrahim** – Team Member
