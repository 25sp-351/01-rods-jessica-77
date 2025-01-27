#include <stdio.h>
#include <stdlib.h>



int maxRod(int lengths[], int values[], int rod, int piece, int max_val[]) {
    max_val[0] = 0;

    // checks if piece length is greater than rod length
    for(int ind=0; ind< piece; ind++) {
        if (lengths[ind] > rod) {
            printf("Piece length %d is greater than rod length %d\n", lengths[ind], rod);
            printf("\n\n");
        }
    }

    // calculates the maximum value of the rod
    for(int length = 1; length <= rod; length++) {
        int max_rev = 0;
        
        for(int ind= 0; ind< piece; ind++) {
            if(lengths[ind] <= length) {
                int val = values[ind] + max_val[length - lengths[ind]];
                if(val > max_rev) {
                    max_rev = val;
                }
            }
        }
        max_val[length] = max_rev;
    }
    return max_val[rod];
    
}

void printPieces(int lengths[], int values[], int rod, int piece, int max_val[]) {
    
    for (int ind = 0; ind < piece; ind++) {
        int remaining = rod;
        
        int totalValue = 0;

        int numPieces = remaining / lengths[ind];

        // calculates the total value of the rod and the remaining length
        if (numPieces > 0) {
            totalValue = numPieces * values[ind];
            remaining -= numPieces * lengths[ind];
        }

        printf("Cutting list:\n");
        if (numPieces > 0) {
            printf("%d @ %d = %d\n", numPieces, lengths[ind], totalValue);
        }

        printf("Remainder: %d\n", remaining);
        printf("Value of rod: %d\n\n", totalValue);
    }
}

int main(int argc, char *argv[]) {

    // checks if there are two arguments ./rods <length>
    if(argc != 2){
        printf("Second argument not found. To run program, do -->  ./rods <length>\n");
        return 1;
    }
    // converts second arg to int
    int rod = atoi(argv[1]); 

    // checks if rod length is greater than 0
    if(rod <= 0) {
        printf("Length of rod must be greater than 0\n");
        return 1;
    }

    int length[5];

    int value[5];

    int piece = 0;

    printf("Enter piece prices with the format : <length>, <value>\n");
    printf("cntrl + D to end input\n");

    while (scanf("%d, %d", &length[piece], &value[piece]) != EOF) {
        piece++;
    }
        // max number of pieces is 5
        if(piece > 5) {
            printf("Max number of pieces reached\n");
            return 1;
        }
        // checks if no pieces are entered
        if(piece == 0) {
            printf("No pieces entered\n");
            return 1;
        }

    int max_val[rod + 1];

    int total_val = maxRod(length, value, rod, piece, max_val);

    printPieces(length, value, rod, piece, max_val);

    printf("Best value : %d\n", total_val);
    return 0;

}