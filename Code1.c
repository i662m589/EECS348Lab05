#include <stdio.h>
void month_sales(double sales_fig[12], char months[12][10]) {
    printf("\nMonthly Sales Report:\n");
    printf("Month   Sales\n");
    for (int m = 0; m < 12; m++) {
        printf("%s  %lf\n", months[m], sales_fig[m]);
    }
    printf("\n");
/*This function takes in the two arrays, goes through a for loop and prints the month array followed by the sales.*/
}
void sales_summary(double sales_fig[12], char month[12][10]) {
    printf("\nSales Summary Report: \n");
    double min = sales_fig[0];
    double max = sales_fig[0];
    int count_min = 0;
    int count_max = 0;
/*These variables will be utilized throughout the remainder of this function.*/
    for (int i = 0; i < 12; i++) {
        if (min > sales_fig[i]) {
            min = sales_fig[i];
            count_min = i;
        }
        if (max < sales_fig[i]) {
            max = sales_fig[i];
            count_max = i;
        }
    }
/*This part of the function finds the index of the maximum and minimum values in the array*/
    double average;
    for (int j = 0; j < 12; j++) {
        average = average + sales_fig[j];
    }
    average = average / 12.0;
/*This adds up all of the values in the sales array and divides it by 12 to find the average*/
    printf("Minimum Sales: %lf (%s)\n", min, month[count_min]);
    printf("Maximum Sales: %lf (%s)\n", max, month[count_max]);
    printf("Average Sales: %lf\n", average);
/*This prints the minimum and maximum sales, their respective months, and the average sales.*/
}
void moving_average(double sales_fig[12], char month[12][10]) {
    printf("\nSix-Month moving average report:\n");
    double jan_jun, feb_jul, mar_aug, apr_sep, may_oct, jul_dec = 0.0;
    double six = 6.0;
/*These doubles will be utilized throughout the remainder of the fucntion*/
    for (int r = 0; r <= 5; r++) {
        jan_jun = jan_jun + sales_fig[r];
    }
    for (int s = 1; s <= 6; s++){
        feb_jul = feb_jul + sales_fig[s];
    }
    for (int t = 2; t <= 7; t++) {
        mar_aug = mar_aug + sales_fig[t];
    }
    for (int u = 3; u <= 8; u++) {
        apr_sep = apr_sep + sales_fig[u];
    }
    for (int v = 4; v <= 9; v++) {
        may_oct = may_oct + sales_fig[v];
    }
    double jun_nov = 0.0;
    for (int w = 5; w <= 10; w++) {
        jun_nov = jun_nov + sales_fig[w];
    }
    for (int x = 6; x <= 11; x++) {
        jul_dec = jul_dec + sales_fig[x];
    }
/*For each of these for loops, the program will go through the respective months, add up the sales, and divide those sales to get the moving average of each time frame.*/
    printf("January-June    %lf\n", jan_jun / six);
    printf("February-July   %lf\n", feb_jul / six);
    printf("March-August    %lf\n", mar_aug / six);
    printf("April-September %lf\n", apr_sep / six);
    printf("May-October     %lf\n", may_oct / six);
    printf("June-November   %lf\n", jun_nov / six);
    printf("July-December   %lf\n", jul_dec / six);
/*This prints the moving averages to the user.*/
}
void sales_report(double sales_fig[12], char month[12][10]) {
    printf("\nSales Report (Highest to Lowest): \n");
    int m, n, temp;
    double temp2;
    int sale_repo[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
/*These are variables that will be utilized throughout the remainder of the function, including an index array.*/
    for (m = 0; m < 11; m++) {
        for (n = 0; n < 11; n++) {
            if (sales_fig[n] < sales_fig[n + 1]) {
                temp = sale_repo[n];
                sale_repo[n] = sale_repo[n + 1];
                sale_repo[n + 1] = temp;

                temp2 = sales_fig[n];
                sales_fig[n] = sales_fig[n + 1];
                sales_fig[n + 1] = temp2;
            }
        }
    }
    for (int o = 0; o < 12; o++) {
        printf("%lf     %s\n", sales_fig[o], month[sale_repo[o]]);
    }
/*This code sorts the index and sales arrays to be from highest to lowest in terms of the sales, then prints the sales and month from highest to lowest.*/
}
int main() {
    int input_num = 0;
    double sales_fig[12];
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August","September", "October","November","December"};
/*These are the variables and arrays that will be used throughout the remainder of the program.*/
    while (input_num < 12) {
        double num;
        printf("Enter a monthly sales figure: ");
        scanf("%lf", &num);
        sales_fig[input_num] = num;
        input_num = input_num + 1;
    }
/*This code asks the user for a monthly sales figure 12 times and inputs those integers into an array*/
    month_sales(sales_fig, months);
    sales_summary(sales_fig, months);
    moving_average(sales_fig, months);
    sales_report(sales_fig, months);
    return 0;
/*This code calls the four functions that will get the monthly sales, sales summary, moving averages, and the sales report with the user's monthly sales figures.*/
}