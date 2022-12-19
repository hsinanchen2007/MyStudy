```
bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    int myArr[1000] = {0};
    int i, j;
    *tripsColSize = 3;
    for (i = 0; i < tripsSize; i++) {
        for (j = trips[i][1]; j < 1000; j++) {
            myArr[j] += trips[i][0];
        }

        for (j = trips[i][2]; j < 1000; j++) {
            myArr[j] -= trips[i][0];
        }
    }

    for (i = 0; i < 1000; i++) {
        if (myArr[i] > capacity) {
            return false;
        }
    }

    return true;
}
```
