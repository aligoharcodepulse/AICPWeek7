//program for manager of super market to record donations to charity 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int customer_bill = 0, choice = 0;
    float charity1 = 0.0, charity2 = 0.0, charity3 = 0.0;
    float total = 0.0, amount_donated = 0.0;

    vector<pair<string, float>> charities = { {"charity1", 0.0}, {"charity2", 0.0}, {"charity3", 0.0}};

    while (true)
    {
        cout << "Enter coustomer shopping bill: " << endl;
        cin >> customer_bill;

        cout << "Enter charity choice 1(charity1), 2(charity2), 3(charity3): " << endl;
        cin >> choice;

        if (choice >= 1 && choice <= 3)
        {
            amount_donated = customer_bill * 0.01;
            cout << "Total amount donated to " << charities[choice - 1].first << " is: " << amount_donated << endl;
            charities[choice - 1].second += amount_donated;
            total += amount_donated;
        }
        else if (choice == -1)
        {
            // Display totals in descending order
            sort(charities.begin(), charities.end(), [](const auto& a, const auto& b) {
                return a.second > b.second;
                });

            // Display the charities and their totals
            cout << "Charities and their totals in descending order:\n";
            for (const auto& charity : charities)
            {
                cout << charity.first << ": " << charity.second << endl;
            }

            cout << "GRAND TOTAL DONATED TO CHARITY: " << total << endl;
            break;
        }
        else
        {
            cout << "You entered Invalid choice!" << endl;
        }
    }
    return 0;
}