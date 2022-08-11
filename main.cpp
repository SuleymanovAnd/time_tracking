#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

struct registration{
    vector <string> name;
    vector <time_t> time;
    vector <double> difference_time;
    vector <bool> status = {false};
};

int main() {

    string command;
    registration task;
    int nCurrentTask = 0;

    while (command != "exit") {
        cout << ": ";
        cin >> command;
        if (command == "begin") {

            if(nCurrentTask != 0 && task.status [nCurrentTask-1] ){ // завершаем предыдущую задачу
                time_t endT = time (nullptr);
                time_t startT = task.time[nCurrentTask-1];
                task.status [nCurrentTask -1] = false;

                task.difference_time.push_back (std::difftime(endT,startT));
                cout << task.name [nCurrentTask-1] << " end.\n";
            }

            time_t t = time (nullptr);
            string tmp;
            cin >> tmp;
            task.name.push_back (tmp);
            task.time.push_back (t);
            if (nCurrentTask == 0) {
                task.status [0] = true;
            }else {
                task.status.push_back (true);
            }
            nCurrentTask++;
            cout << "New task created successfully\n";
        }
        if (command == "end") {
            if (task.status [nCurrentTask-1]){
            time_t endT = time (nullptr);
            time_t startT = task.time[nCurrentTask-1];

            task.difference_time.push_back (std::difftime(endT,startT));
            task.status [nCurrentTask -1] = false;
            cout << task.name [nCurrentTask-1] << " end.\n";}
            else {cout << "no active tasks\n";}
        }
        if (command == "status") {

            for (int i = 0; i < nCurrentTask;i++){
                cout << i+1 << ") "<< task.name [i] << " ";
                if (!task.status[i]) {cout << task.difference_time [i]<< " sec.";}
                cout << endl;
            }
        }
    }
}
