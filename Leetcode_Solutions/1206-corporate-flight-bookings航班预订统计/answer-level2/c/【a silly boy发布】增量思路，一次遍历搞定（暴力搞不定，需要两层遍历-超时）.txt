```
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize){
    int i;
    int j;
    int *returnValue;
    int *tmpValue;
    if (n == 0) {
        *returnSize = 0;
        return NULL; 
    }

    if ((bookings == NULL) || (bookingsSize == 0) || (bookingsColSize == NULL) || (*bookingsColSize == 0)) {
        returnValue = (int *)malloc(n * sizeof(int));
        memset(returnValue, 0, n * sizeof(int));
        *returnSize = n;
        return returnValue;
    }

    returnValue = (int *)malloc(n * sizeof(int));
    memset(returnValue, 0, n * sizeof(int));

    tmpValue = (int *)malloc((20000 + 2) * sizeof(int));
    memset(tmpValue, 0, (20000 + 2) * sizeof(int));

    for (i = 1; i <= bookingsSize; i++) {
        tmpValue[bookings[i - 1][0]] = tmpValue[bookings[i - 1][0]] + bookings[i - 1][2];
        tmpValue[bookings[i - 1][1] + 1] = tmpValue[bookings[i - 1][1] + 1] - bookings[i - 1][2];
        /*
        for (j = 1; j <= n; j++) {
            printf("tmpValue[%d]:%d\n", j, tmpValue[j]);
        }
        printf("tt\n");
        */
    }

     for (i = 1; i <= n; i++) {
        tmpValue[i] += tmpValue[i - 1];
    }   

    for (i = 1; i <= n; i++) {
        returnValue[i - 1] = tmpValue[i];
    }

    *returnSize = n;
    return returnValue;
}
```
