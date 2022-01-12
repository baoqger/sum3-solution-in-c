#include <stdio.h>
#include <stdlib.h>

void getRandInt(int *dataArr, int dataSize) {
    int num;
    for (int i = 0; i < dataSize; i++) {
        num = rand() % 100  + 1;
        if (rand() % 2 == 0) {
            num *= -1; 
        } 
        dataArr[i] = num;
        // *(dataArr + 1) = num; 
    }
}

int main(int argc, char *argv[]) {
    int dataSize = 0; 

    if (argc < 2) {
        printf("usage: sum3 [num of nums] [optional seed value]\n");
        exit(-1);
    }
    dataSize = atoi(argv[1]);

    if (argc >= 3 ) {
        int seed;
        seed = atoi(argv[2]);
        srand(seed);
    }

    int data[dataSize];

    getRandInt(data, dataSize);

    int *dataPtr = data;

    int count = 0;

    for (int i = 0; i < dataSize - 2; i++) {
        for (int j = i + 1; j < dataSize - 1; j++) {
            for (int k = j + 1; k < dataSize; k++) {
                if (dataPtr[i] + dataPtr[j] + dataPtr[k] == 0) {
                    count++;
                }
            }
        }
    }

    printf("count: %d\n", count);
}
