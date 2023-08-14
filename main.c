#include <stdio.h>

// function to check if the given year is a leap year
int isLeapYear(int year) {
    if(year % 400 == 0) {
        return 1;
    }
    if(year % 100 == 0) {
        return 0;
    }
    if(year % 4 == 0) {
        return 1;
    }
    return 0;
}

// function to calculate the day of the week for a given date using Zeller's formula

int calculateDayOfTheWeek(int day, int month, int year) {
    if(month < 3){
        month += 12;
        year--;
    }

    int K = year % 100;
    int J = year / 100;

    int h = (day + ((13 * (month + 1)) / 5) + K + (K/4) + (J/4) - (2 * J)) % 7; // Zeller's Formula for the gregorian calendar

    // if(h < 0){
    //     h += 7;
    // }

    return h;

}

// function to display the calendar for a specific month and year
void displayCalendar(int month, int year){ 
    // month names
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


    // day names
    char *days[] = {"S", "S", "M", "T", "W", "T", "F"};

    // total number of days in each month
    int numDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // check for leap year
    if(isLeapYear(year)) {
        numDays[1] = 29;
    }

    // calculate the day of the week for the first day of the month
    int dayOfWeek = calculateDayOfTheWeek(1, month, year);

    // Calendar Header
    printf("=============================\n");
    printf("        %s %d\n", months[month - 1], year);
    printf("=============================\n");

    // day names
    for(int i = 0; i < 7; i++){
        printf("%3s ", days[i]);
    }
    printf("\n");

    // print the empty cells before the days of the month
    for(int i = 0; i < dayOfWeek; i++){
        printf("    ");
    }

    int day = 1;
    // print the days of the month
    for(int i = dayOfWeek; i < 7; i++){
        printf("%3d ", day);
        day++;
    }
    printf("\n");

    // print the remaining days of the month
    while(day <= numDays[month - 1]){
        for (int i = 0; i < 7 && day <= numDays[month - 1]; i++){
            printf("%3d ", day);
            day++;
        }
        printf("\n");
    }
    printf("=============================\n");


}


int main() {
    int month, year;

    printf("Enter month(1 - 12): ");
    scanf("%d", &month);    

    printf("Enter year: ");
    scanf("%d",&year);

    displayCalendar(month, year);
    
    return 0;
}