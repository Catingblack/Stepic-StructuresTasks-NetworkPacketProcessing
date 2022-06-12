#include <iostream>
#include <queue>

using namespace std;


void getPocket(int* arr, int* dur, int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        cin >> dur[i];
    }
}

void addBuff(queue <int> * Q1, int* arr, int* dur, int i) {
    int timeEnd;
    timeEnd = (*Q1).back();

    if( timeEnd > arr[i]) {
        (*Q1).push(timeEnd + dur[i]);
        cout << timeEnd << endl;
    }
    else {
        (*Q1).push(arr[i] + dur[i]);
        cout << arr[i] << endl;
    }
}

void timeBegginPack(int s, int n, int* arr, int* dur) {

    queue <int> myBuff;

    for(int i = 0; i < n; i++) {

        if(myBuff.empty()) {
            myBuff.push(arr[i] + dur[i]);
            cout << arr[i] << endl;
            continue;
        }

        if(myBuff.size() < s) {
            addBuff(&myBuff, arr, dur, i);
        }

        else {
            if(myBuff.front() > arr[i]) {
                cout << -1 << endl;
            }
            else {
                myBuff.pop();
                addBuff(&myBuff, arr, dur, i);
            }
        }
    }
}

int main()
{
    //Инициализация
    int s, n;
    int* arr;
    int* dur;

    cin >> s;
    cin >> n;

    arr = new int[n];
    dur = new int[n];


    // Операции
    getPocket(arr, dur, n);
    timeBegginPack(s, n, arr, dur);



    //Очищение
    delete [] arr;
    delete [] dur;

    return 0;
}
