#include <stdio.h>
#include <stdlib.h>


int update_seen(int rows[], int d1[], int d2[], int col_number, int board_size, int j); 
int queens(int rows[], int d1[], int d2[], int col_number, int board_size);

int update_seen(int rows[], int d1[], int d2[], int col_number, int board_size, int j) {
    rows[j] = 1; 
    d1[j + col_number] = 1;
    d2[board_size - j + col_number - 1] = 1;
    int number_of_placements = queens(rows, d1, d2, col_number + 1, board_size);
    rows[j] = 0; 
    d1[j + col_number] = 0;
    d2[board_size -j + col_number - 1] = 0;
    return number_of_placements;
}

int queens(int rows[], int d1[], int d2[], int col_number, int board_size) {
    
    if (col_number == board_size) return 1;
    int number_of_placements = 0;
    if (col_number == 0) {
	for (int j = 0; j < board_size/2; j++) 
    	    number_of_placements += 2 * update_seen(rows, d1, d2, col_number, board_size, j);
	if (board_size % 2 == 1)
	    number_of_placements += update_seen(rows, d1, d2, col_number, board_size, board_size/2);
    } else {
        for (int j = 0; j < board_size; j++) {
            if (rows[j] == 0 && d1[j + col_number] == 0 && d2[board_size - j + col_number - 1] == 0) 
		number_of_placements += update_seen(rows, d1, d2, col_number, board_size, j);
         }
    }
    return number_of_placements;
}

int main(int argc, char ** argv) {
    int board_size; 
    printf("Enter your board size: ");
    scanf("%d", &board_size);
    int rows[board_size];
    int d1[2*board_size - 1];
    int d2[2*board_size - 1];
    for (int i = 0; i < board_size; i++) {
	rows[i] = 0;
	d1[2*i] = 0; 
	d1[2*i + 1] = 0;
	d2[2*i] = 0; 
	d2[2*i + 1] = 0;
    }
    
    printf("The queen number is %d\n", queens(rows, d1, d2, 0, board_size));
}
