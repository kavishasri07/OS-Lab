#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid, at, bt, ct, tat, wt;
    bool completed = false;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Process P" << i + 1 << endl;
        cout << "Arrival Time: ";
        cin >> p[i].at;
        cout << "Burst Time: ";
        cin >> p[i].bt;
    }

    int completed = 0;
    int currentTime = 0;
    float totalWT = 0, totalTAT = 0;

    while (completed < n) {

        int idx = -1;
        int minBT = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].at <= currentTime) {

                if (p[i].bt < minBT) {
                    minBT = p[i].bt;
                    idx = i;
                }
                else if (p[i].bt == minBT) {
                    if (p[i].at < p[idx].at)
                        idx = i;
                }
            }
        }

        if (idx == -1) {
            currentTime++;
            continue;
        }

        currentTime += p[idx].bt;

        p[idx].ct = currentTime;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;
        p[idx].completed = true;

        totalWT += p[idx].wt;
        totalTAT += p[idx].tat;

        completed++;
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].ct << "\t"
             << p[i].tat << "\t"
             << p[i].wt << endl;
    }

    cout << fixed << setprecision(2);
    cout << "Average Turnaround Time: " << totalTAT / n << endl;
    cout << "Average Waiting Time: " << totalWT / n << endl;
    cout<<"Name: Kavisha Srivastava \n";
    cout<<"Roll No: 2503215300095 \n";
    cout<<"Branch: CSE AIML \n";
    cout<<"Section: A \n";

    return 0;
}