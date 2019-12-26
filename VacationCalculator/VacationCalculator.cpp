This program is written by Pikulkaew Boonpeng.
#include <iostream>
using namespace std;

void print(int, string, string, string);
int calWeekAmount(int, string, string, string);
int calLastDay(int, int);
int calFirstDay(int, int);
int calIndex(string, string[], int);

// array for months
string MONTHS[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// length of the month
int LENGTH_MONTH[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// array for days of the week
string DAYS[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main() {
    print(2001, "April", "May", "Monday");
    print(2001, "October", "December", "Monday");
    print(2003, "April", "May", "Wednesday");
    print(2019, "April", "May", "Tuesday");
    print(2019, "June", "July", "Tuesday");
    return 0;
}

// Prints infomation and amount of vacation weeks
void print(int Y, string A, string B, string W){
    cout << "Year: " << Y
         << "\nFirst day of year: " << W
         << "\nBegin Month: " << A
         << "\nEnd Month: " << B
         << "\nAmount of vacation weeks: " << calWeekAmount(Y, A, B, W) << "\n\n";
}

// Returns amount of vacation weeks
int calWeekAmount(int Y, string A, string B, string W) {
    
    // check leap year
    if (Y % 4 == 0) {
        LENGTH_MONTH[1] += 1;
    }
    
    //-------get index of each input String------
    int A_Index = calIndex(A, MONTHS, 12),
    B_Index = calIndex(B, MONTHS, 12),
    W_Index = calIndex(W, DAYS, 7);
    //--------------------------------------------
    
    //----cal fully week btw those two months-----
    int sumDaysAB = 0;
    for (int i = A_Index; i <= B_Index; i++) {
        sumDaysAB += LENGTH_MONTH[i];
    }
    
    if (calFirstDay(A_Index, W_Index) != 0) {
        sumDaysAB = sumDaysAB - 7 + calFirstDay(A_Index, W_Index);
    }
    if (calLastDay(B_Index, W_Index) != 6) {
        sumDaysAB = sumDaysAB - calLastDay(B_Index, W_Index) - 1;
    }
    //--------------------------------------------
    
    return sumDaysAB / 7;
}

// Returns last day of end month
int calLastDay(int B, int W){
    int sumB = 0, lastDayB = 0;
    for (int i = 0; i <= B; i++) {
        sumB += LENGTH_MONTH[i];
    }
    
    lastDayB = sumB % 7 + W - 1;
    
    if (lastDayB == -1) {
        lastDayB = 6;
    }
    if (lastDayB >= 7) {
        lastDayB -= 7;
    }
    
    return lastDayB;
}

// Returns first day of begin month
int calFirstDay(int A, int W){
    int sumA = 0, firstDayA = 0;
    for (int i = 0; i < A; i++) {
        sumA += LENGTH_MONTH[i];
    }
    
    firstDayA = sumA % 7 + W;
    
    if (firstDayA >= 7) {
        firstDayA -= 7;
    }
    
    return firstDayA;
}

// Returns index of month and day
int calIndex(string str, string arr[], int size) {
    int index = 0;
    
    for (int i = 0; i < size; i++) {
        if (str == arr[i]) {
            index = i;
        }
    }
    return index;
}
