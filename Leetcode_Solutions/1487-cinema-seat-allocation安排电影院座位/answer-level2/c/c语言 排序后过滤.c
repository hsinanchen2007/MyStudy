```
int MyCmp(const void *p1, const void *p2)
{
    return ((int **)p1)[0][0] - ((int **)p2)[0][0];
}

int g_left = 0xf << 5;
int g_mid = 0xf << 3;
int g_right = 0xf << 1;

int GetMinusCount(int leftTemp, int midTemp, int rightTemp, int xorTemp)
{
    int count = 0;

    leftTemp = (xorTemp & g_left) ^ g_left;
    midTemp =  (xorTemp & g_mid) ^ g_mid;
    rightTemp = (xorTemp & g_right) ^ g_right;

    if (midTemp == g_mid) {
        if (leftTemp == g_left && rightTemp == g_right) {
            count += 0;
        } else if (leftTemp != g_left || rightTemp != g_right) {
            count += 1;
        }
    } else {
        if (leftTemp != g_left && rightTemp != g_right) {
            count += 2;
        } else if (leftTemp == g_left || rightTemp == g_right) {
            count += 1;
        }
    }

    return count;
}



int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize){
    int i;
    int temp;
    int leftTemp;
    int midTemp;
    int rightTemp;
    int xorTemp;
    int max = 2 * n;
    int count;

    qsort(reservedSeats, reservedSeatsSize, sizeof(int**), MyCmp);

    count = 0;
    xorTemp = 0;
    temp = reservedSeats[0][0];

    for (i = 0; i < reservedSeatsSize; i++) {
        if (reservedSeats[i][0] != temp) {
            count += GetMinusCount(leftTemp, midTemp, rightTemp, xorTemp);
            leftTemp = g_left;
            midTemp = g_mid;
            rightTemp = g_right;
            xorTemp = 0;
            temp = reservedSeats[i][0];
        }

        xorTemp |= (0x1 << (10 - reservedSeats[i][1]));
    }

    count += GetMinusCount(leftTemp, midTemp, rightTemp, xorTemp);

    return max - count;
}
```
