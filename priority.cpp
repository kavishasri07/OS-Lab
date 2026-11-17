#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid, at, bt, ct, tat, wt;
    int priority; 
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

        cout << "Priority: ";
        cin >> p[i].priority;
    }

    int completed = 0;
    int currentTime = 0;
    float totalWT = 0, totalTAT = 0;

    while (completed < n) {

        int idx = -1;
        int highestPriority = INT_MAX;

        for (int i = 0; i < n; i++) {

            if (!p[i].completed && p[i].at <= currentTime) {

                if (p[i].priority < highestPriority) {
                    highestPriority = p[i].priority;
                    idx = i;
                }

                else if (p[i].priority == highestPriority) {

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

    cout << "PID\tAT\tBT\tPR\tCT\tTAT\tWT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].priority << "\t"
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