#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter no. of processes: ";
    cin >> n;

    cout << "Enter no. of resources: ";
    cin >> m;

    int allo[10][10], maxNeed[10][10], need[10][10];
    int avail[10], work[10], finish[10] = {0};

    int safeSeq[10];

    cout << "Enter Allocation Matrix: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> allo[i][j];
        }
    }

    cout << "Enter Maximum Matrix: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maxNeed[i][j];
        }
    }

    cout << "Enter Available Resources: ";
    for (int j = 0; j < m; j++)
    {
        cin >> avail[j];
    }

    // Calculate Need Matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = maxNeed[i][j] - allo[i][j];
        }
    }

    // Copy Available into Work
    for (int j = 0; j < m; j++)
    {
        work[j] = avail[j];
    }

    int count = 0;

    while (count < n)
    {
        bool found = false;

        for (int i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                bool possible = true;

                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        possible = false;
                        break;
                    }
                }

                if (possible)
                {
                    for (int j = 0; j < m; j++)
                    {
                        work[j] = work[j] + allo[i][j];
                    }

                    safeSeq[count] = i;
                    count++;
                    finish[i] = 1;
                    found = true;
                }
            }
        }

        if (!found)
        {
            cout << "System is not in safe state";
            return 0;
        }
    }

    cout << "\nSystem is in safe state\n";
    cout << "Safe Sequence: ";

    for (int i = 0; i < n; i++)
    {
        cout << "P" << safeSeq[i];

        if (i != n - 1)
        {
            cout << " -> ";
        }
    }
    cout << endl;
    cout<<"Name: Kavisha Srivastava \n";
    cout<<"Roll No: 2503215300095 \n";
    cout<<"Branch: CSE AIML \n";
    cout<<"Section: A \n";

    return 0;
}