#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MONTHS 12

void readdata(double sales_data[], char *file_path) {   //Read input function
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {         
        printf("Invalid file.\n");
        exit(1);
    }
    for (int i = 0; i < MAX_MONTHS; i++) {
        fscanf(file, "%lf", &sales_data[i]);
    }
    fclose(file);
}

void monthly_report(double sales_data[]) {  // generate and print out Monthly sales report format.
    char *months[] = {"January", "February", "March", "April", "May", "June", "July",
                      "August", "September", "October", "November", "December"};

    printf("Monthly sales report for 2022:\n");
    printf("%10s %10s\n", "Month", "Sales");
    for (int i = 0; i < MAX_MONTHS; i++) {
        printf("%-10s $%-10.2f\n", months[i], sales_data[i]);
    }
}

void sale_sum(double sales_data[]) {    //Get min, max and average sales
    double min_sales = sales_data[0];
    double max_sales = sales_data[0];
    double sum_sales = 0.0;
    int min_month = 0, max_month = 0;
    char *months[] = {"January", "February", "March", "April", "May", "June", "July",
                      "August", "September", "October", "November", "December"};

    for (int i = 0; i < MAX_MONTHS; i++) {
        if (sales_data[i] < min_sales) {
            min_sales = sales_data[i];
            min_month = i;
        }
        if (sales_data[i] > max_sales) {
            max_sales = sales_data[i];
            max_month = i;
        }
        sum_sales += sales_data[i];
    }

    double avg_sales = sum_sales / MAX_MONTHS;

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min_sales, months[min_month]);
    printf("Maximum sales: $%.2f (%s)\n", max_sales, months[max_month]);
    printf("Average sales: $%.2f\n", avg_sales);
}

void six_month(double sales_data[]) {   //aveage of sales in each 6 months 
    char *months[] = {"January", "February", "March", "April", "May", "June", "July",
                      "August", "September", "October", "November", "December"};

    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i <= MAX_MONTHS - 6; i++) {
        double sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            sum += sales_data[j];
        }
        double avg = sum / 6.0;
        printf("%-10s - %-10s $%.2f\n", months[i], months[i + 5], avg);
    }
}

void sorted_sales(double sales_data[]) { // print out descending order list of sales to months
    double sorted_sales[MAX_MONTHS];
    memcpy(sorted_sales, sales_data, sizeof(double) * MAX_MONTHS);

    char *months[] = {"January", "February", "March", "April", "May", "June", "July",
                      "August", "September", "October", "November", "December"};

    for (int i = 0; i < MAX_MONTHS - 1; i++) {
        for (int j = 0; j < MAX_MONTHS - i - 1; j++) {
            if (sorted_sales[j] < sorted_sales[j + 1]) {
                double temp = sorted_sales[j];
                sorted_sales[j] = sorted_sales[j + 1];
                sorted_sales[j + 1] = temp;
            }
        }
    }

    printf("\nSales Report (Highest to Lowest):\n");
    printf("%5s %10s\n", "Month", "Sales");
    for (int i = 0; i < MAX_MONTHS; i++) {
        for (int j = 0; j < MAX_MONTHS; j++) {
            if (sales_data[j] == sorted_sales[i]) {
                printf("%-10s $%-10.2f\n", months[j], sorted_sales[i]);
                break;
            }
        }
    }
}

int main() {
    double sales_data[MAX_MONTHS];
    readdata(sales_data, "input.txt");
    monthly_report(sales_data);
    sale_sum(sales_data);
    six_month(sales_data);
    sorted_sales(sales_data);

    return 0;
}
