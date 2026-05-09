#include <iostream>
#include <vector>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

using namespace std;

int main() {

    string name;

    // Ask the user to enter their name
    cout << "Enter student name: ";
    getline(cin, name);

    // Check if the input is empty
    if (name.empty()) {
        cout << "Invalid input! Please enter a valid name." << endl;
        return 0;
    }

    // Store excuse templates in a vector
    vector<string> excuses = {

        "{name} couldn't finish the assignment because the laptop battery died unexpectedly.",

        "{name} tried finishing the homework, but the internet stopped working.",

        "{name} was ready to submit the assignment when the file mysteriously disappeared.",

        "{name} couldn't complete the homework because the laptop started updating for hours.",

        "{name} was about to finish the assignment when the Wi-Fi suddenly vanished.",

        "{name} tried typing the homework, but the keyboard stopped cooperating.",

        "{name} accidentally deleted the assignment while organizing folders.",

        "{name} couldn't complete the work because the computer froze suddenly.",

        "{name} stayed up to finish the assignment, but the power went out unexpectedly.",

        "{name} completed the homework, but the USB drive refused to open.",

        "{name} almost finished the assignment when the screen turned blue.",

        "{name} worked hard on the homework, but the internet disconnected before submission."
    };

    // Seed the random number generator
    // This helps generate different excuses each time
    srand(time(0));

    // Generate a random index number
    int randomIndex = rand() % excuses.size();

    // Get a random excuse from the vector
    string excuse = excuses[randomIndex];

    // Replace {name} with the actual student name
    size_t pos = excuse.find("{name}");

    while (pos != string::npos) {
        excuse.replace(pos, 6, name);
        pos = excuse.find("{name}");
    }

    // Display the final excuse
    cout << "\nGenerated Excuse:\n";
    cout << excuse << endl;

    return 0;
}
