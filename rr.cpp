#include <bits/stdc++.h>
using namespace std;
struct Process {
    int pid, at, bt, rt, ct, tat, wt;
};
int main() {
    int n, tq;
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
        p[i].rt = p[i].bt;
    }
    cout << "Enter Time Quantum: ";
    cin >> tq;
    queue<int> q;
    vector<bool> visited(n, false);
    int currentTime = 0;
    int completed = 0;
    float totalWT = 0, totalTAT = 0;
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (!visited[i] && p[i].at <= currentTime) {
                q.push(i);
                visited[i] = true;
            }
        }
        if (q.empty()) {
            currentTime++;
            continue;
        }
        int idx = q.front();
        q.pop();
        if (p[idx].rt > tq) {
            p[idx].rt -= tq;
            currentTime += tq;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && p[i].at <= currentTime) {
                    q.push(i);
                    visited[i] = true;
                }
            }
            q.push(idx);
        }
        else {
            currentTime += p[idx].rt;
            p[idx].rt = 0;
            p[idx].ct = currentTime;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            totalWT += p[idx].wt;
            totalTAT += p[idx].tat;
            completed++;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && p[i].at <= currentTime) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
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