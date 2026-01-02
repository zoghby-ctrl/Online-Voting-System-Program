#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int MAX_CANDIDATES = 10; // Max 10 candidates allowed

struct Candidate {
    string name;
    int voteCount;
};

// Global variables so all functions can see them
Candidate candidateList[MAX_CANDIDATES];
int currentCandidateCount = 0;

void addCandidate();
void castVote();
void displayResults();
void declareWinner();
void saveResultsToFile();

int main() {
    int choice;

    // Loop until the user chooses option 4
    do {
        cout << "\n=== VOTING MENU ===\n";
        cout << "1. Add a Candidate\n";
        cout << "2. Vote\n";
        cout << "3. View Scores\n";
        cout << "4. Declare Winner & Exit (Saves to File)\n";
        cout << "Enter choice: ";
        cin >> choice;

        // Code to fix the infinite loop if someone types a letter instead of a number
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            choice = 0;
        }

        switch (choice) {
        case 1: addCandidate(); break;
        case 2: castVote(); break;
        case 3: displayResults(); break;
        case 4:
            declareWinner(); // Show who won before leaving
            saveResultsToFile(); // Save the bonus file
            cout << "Goodbye!\n";
            break;
        default: cout << "Invalid choice, try again.\n";
        }

    } while (choice != 4);

    return 0;
}

void addCandidate() {
    // First check if the array is full
    if (currentCandidateCount >= MAX_CANDIDATES) {
        cout << "Sorry, the candidate list is full!\n";
        return;
    }

    cout << "Enter candidate name: ";
    cin >> candidateList[currentCandidateCount].name;

    // Start them with 0 votes
    candidateList[currentCandidateCount].voteCount = 0;

    // Increase the counter so we know how many people we have
    currentCandidateCount++;
    cout << "Added successfully!\n";
}

void castVote() {
    // Safety check: can't vote if nobody is on the list
    if (currentCandidateCount == 0) {
        cout << "No candidates yet! Add some first.\n";
        return;
    }

    int userChoice;
    cout << "\n--- Who do you want to vote for? ---\n";
    // Loop to show all the names
    for (int i = 0; i < currentCandidateCount; i++) {
        cout << (i + 1) << ". " << candidateList[i].name << endl;
    }

    cout << "Enter the ID number: ";
    cin >> userChoice;

    // Check if the number they typed is real
    if (userChoice < 1 || userChoice > currentCandidateCount) {
        cout << "Invalid ID!\n";
    }
    else {
        // -1 because array index starts at 0, but our list started at 1
        int correctIndex = userChoice - 1;
        candidateList[correctIndex].voteCount++;
        cout << "Vote counted for " << candidateList[correctIndex].name << ".\n";
    }
}

void displayResults() {
    if (currentCandidateCount == 0) {
        cout << "List is empty.\n";
        return;
    }

    cout << "\n--- Standings ---\n";
    for (int i = 0; i < currentCandidateCount; i++) {
        cout << candidateList[i].name << ": " << candidateList[i].voteCount << " votes\n";
    }
}

void declareWinner() {
    // FIX: prevent crash if list is empty
    if (currentCandidateCount == 0) {
        cout << "No candidates to declare a winner!\n";
        return;
    }

    int highestVotes = -1;
    int winnerIndex = -1;

    // Loop through everyone to find the biggest number
    for (int i = 0; i < currentCandidateCount; i++) {
        if (candidateList[i].voteCount > highestVotes) {
            highestVotes = candidateList[i].voteCount;
            winnerIndex = i;
        }
    }

    cout << "\n!!! THE WINNER IS " << candidateList[winnerIndex].name << " !!!\n";
}

void saveResultsToFile() {
    // FIX: don't save empty files
    if (currentCandidateCount == 0) return;

    // Create the file
    ofstream myFile("election_results.txt");

    if (myFile.is_open()) {
        myFile << "--- FINAL RESULTS ---\n";
        // Write the data just like we print it to the screen
        for (int i = 0; i < currentCandidateCount; i++) {
            myFile << candidateList[i].name << ": " << candidateList[i].voteCount << "\n";
        }
        myFile << "---------------------\n";
        myFile.close(); // Close it to save changes
        cout << "Results saved to 'election_results.txt'.\n";
    }
    else {
        cout << "Error: Could not create file.\n";
    }
}
