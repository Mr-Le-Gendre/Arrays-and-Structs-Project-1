#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;

// Parallel arrays to store information about each runner
string runnerNames[NUM_RUNNERS];
int miles[NUM_RUNNERS][NUM_DAYS];
int totalMiles[NUM_RUNNERS];
double avgMiles[NUM_RUNNERS];

// Function Prototypes
void readDataFromFile(const string& filename);
void calculateTotalAndAverageMiles();
void outputResults();

// Preconditions:
// - filename is the name of the file containing the data.
// Postconditions: Data from the file is stored in parallel arrays.

// Function to read and store data from file
void readDataFromFile(const string& filename) {
    ifstream file(filename); // Open the file for reading
    if (!file.is_open()) { // Check if the file is opened successfully
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1); // Exit the program with error status
    }

    // Loop through each runner and read their data from the file
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        file >> runnerNames[i]; // Read runner's name
        totalMiles[i] = 0; // Initialize total miles for the runner
        // Loop through each day and read miles run by the runner
        for (int j = 0; j < NUM_DAYS; ++j) {
            file >> miles[i][j];
            totalMiles[i] += miles[i][j]; // Calculate total miles for the runner
        }
        // Calculate average miles for the runner
        avgMiles[i] = static_cast<double>(totalMiles[i]) / NUM_DAYS;
    }

    file.close(); // Close the file
}

// Preconditions:
// - Parallel arrays contain data about each runner.
// Postconditions: totalMiles and avgMiles arrays are populated.

// Function to calculate total and average miles
void calculateTotalAndAverageMiles() {
    // Loop through each runner
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        totalMiles[i] = 0; // Initialize total miles for the runner
        // Loop through each day and calculate total miles for the runner
        for (int j = 0; j < NUM_DAYS; ++j) {
            totalMiles[i] += miles[i][j];
        }
        // Calculate average miles for the runner
        avgMiles[i] = static_cast<double>(totalMiles[i]) / NUM_DAYS;
    }
}

// Preconditions:
// - Parallel arrays contain data about each runner.
// Postconditions: Results are displayed in a tabular format.

// Function to output results
void outputResults() {
    // Print table headers
    cout << setw(15) << "Runner Name";
    for (int i = 1; i <= NUM_DAYS; ++i) {
        cout << setw(10) << "Day " << i;
    }
    cout << setw(15) << "Total Miles" << setw(15) << "Avg Miles" << endl;

    // Print data for each runner
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        cout << setw(15) << runnerNames[i]; // Print runner's name
        // Print miles run by the runner each day
        for (int j = 0; j < NUM_DAYS; ++j) {
            cout << setw(10) << miles[i][j];
        }
        // Print total miles and average miles for the runner
        cout << setw(15) << totalMiles[i] << setw(15) << fixed << setprecision(2) << avgMiles[i] << endl;
    }
}

int main() {
    readDataFromFile("Runners.txt"); // Read data from file
    calculateTotalAndAverageMiles(); // Calculate total and average miles
    outputResults(); // Output results
    return 0;
}

