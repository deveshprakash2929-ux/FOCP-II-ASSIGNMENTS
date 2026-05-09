#include <iostream>
#include <vector>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

using namespace std;

int main() {

    string name;

    // Ask the user to enter their name
    cout << "Enter your name: ";
    getline(cin, name);

    // Check if the input is empty
    if (name.empty()) {
        cout << "Invalid input! Please enter a valid name." << endl;
        return 0;
    }

    // Vector storing funny roast templates
    vector<string> roasts = {
        "{name} studies so hard... yet Google still works overtime.",
        "{name}'s coding speed makes turtles look fast.",
        "If laziness had a king, it would definitely be {name}.",
        "{name} opens YouTube for 5 minutes and disappears for 5 hours.",
        "{name}'s WiFi gets tired just watching them scroll memes.",
        "{name} says 'I'll do it tomorrow' like it's a life motto.",
        "{name}'s alarm clock has officially given up.",
        "{name} could lose a race against buffering.",
        "{name} writes code that even the compiler laughs at.",
        "{name} treats deadlines like suggestions.",
        "{name} spends more time choosing music than studying.",
        "{name}'s calculator needs therapy after exam season."
    };

    // Seed random number generator
    srand(time(0));

    // Generate random index
    int randomIndex = rand() % roasts.size();

    // Get random roast
    string roast = roasts[randomIndex];

    // Replace {name} with actual user name
    size_t pos = roast.find("{name}");

    while (pos != string::npos) {
        roast.replace(pos, 6, name);
        pos = roast.find("{name}");
    }

    // Display final roast
    cout << "\nFunny Roast:\n";
    cout << roast << endl;

    return 0;
}
