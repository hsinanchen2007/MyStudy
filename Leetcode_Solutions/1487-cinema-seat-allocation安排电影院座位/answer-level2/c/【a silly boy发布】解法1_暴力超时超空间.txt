![D15AD857-C052-46DD-BA06-03CA8DFE2380.jpeg](https://pic.leetcode-cn.com/d28f7cb1378e3df9666446f847779573c6c052c7466f4948586bad9fcc23b5d9-D15AD857-C052-46DD-BA06-03CA8DFE2380.jpeg)

```
#define COLSIZE 10

int HaxFamilyNum(bool *seatsEnum)
{
    int returnCount = 0;
    if ((seatsEnum[1] == 1) || (seatsEnum[2] == 1)) {
        if ((seatsEnum[7] == 1) || (seatsEnum[8] == 1)) {
            if ((seatsEnum[3] == 1) || (seatsEnum[4] == 1) || (seatsEnum[5] == 1) || (seatsEnum[6] == 1)) {
                returnCount = 0;
            } else {
                returnCount = 1;
            }
        } else {
            if ((seatsEnum[3] == 0) && (seatsEnum[4] == 0) && (seatsEnum[5] == 0) && (seatsEnum[6] == 0)) {
                returnCount = 1;
            } else if ((seatsEnum[7] == 0) && (seatsEnum[8] == 0) && (seatsEnum[5] == 0) && (seatsEnum[6] == 0)) {
                returnCount = 1;
            } else {
                returnCount = 0;
            }
        }
    } else if ((seatsEnum[7] == 1) || (seatsEnum[8] == 1)) {
        if ((seatsEnum[1] == 1) || (seatsEnum[2] == 1)) {
            if ((seatsEnum[3] == 1) || (seatsEnum[4] == 1) || (seatsEnum[5] == 1) || (seatsEnum[6] == 1)) {
                returnCount = 0;
            } else {
                returnCount = 1;
            }
        } else {
            if ((seatsEnum[3] == 0) && (seatsEnum[4] == 0) && (seatsEnum[5] == 0) && (seatsEnum[6] == 0)) {
                returnCount = 1;
            } else if ((seatsEnum[1] == 0) && (seatsEnum[2] == 0) && (seatsEnum[3] == 0) && (seatsEnum[4] == 0)) {
                returnCount = 1;
            } else {
                returnCount = 0;
            }
        }  
    } else if ((seatsEnum[3] == 1) || (seatsEnum[4] == 1)) {
        if ((seatsEnum[5] == 0) && (seatsEnum[6] == 0)) {
            returnCount = 1;
        } else {
            returnCount = 0;
        }
    } else if ((seatsEnum[5] == 1) || (seatsEnum[6] == 1)) {
        if ((seatsEnum[3] == 0) && (seatsEnum[4] == 0)) {
            returnCount = 1;
        } else {
            returnCount = 0;
        }
    } else {
        returnCount = 2;
    }
    return returnCount;
}

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize){
    if (n == 0) {
        return 0;
    }
    if ((reservedSeats == NULL) || (reservedSeatsSize == 0) || (reservedSeatsColSize == NULL) || (*reservedSeatsColSize == 0)) {
        return 2 * n;
    }
    
    int i;
    int returnCount = 0;
    int tmpCount = 0;
    bool **seats = (bool **)malloc(n * sizeof(bool *));
    for (i = 0; i < n; i++) {
        seats[i] = (bool *)malloc(COLSIZE * sizeof(bool));
        memset(seats[i], false, COLSIZE * sizeof(bool));
    }
    for (i = 0; i < reservedSeatsSize; i++) {
        if (reservedSeats != NULL) {
            seats[reservedSeats[i][0] - 1][reservedSeats[i][1] - 1] = 1;
        }
    }
    
    for (i = 0; i < n; i++) {
        tmpCount = HaxFamilyNum(seats[i]);
        //printf("tmpCount: %d\n", tmpCount);
        returnCount = returnCount + tmpCount;
    }
    
    return returnCount;
}
```
