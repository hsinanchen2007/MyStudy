```c

int Cmp(const void* a, const void* b)
{
    int** aa = (int**)a;
    int** bb = (int**)b;
    return **aa - **bb;
}

bool ExistNum(int* seat, int size, int num)
{
    int i;
    for (i = 0; i < size; ++i) {
        if (seat[i] == num) {
            return true;
        }
    }
    return false;
}

int DecreaseFamily(int* seat, int size)
{
    int i;
    int ret = 0;
    if (ExistNum(seat, size, 2) || ExistNum(seat, size, 3) || ExistNum(seat, size, 4) || ExistNum(seat, size, 5)) {
        ++ret;
    }
    if (ExistNum(seat, size, 8) || ExistNum(seat, size, 9) || ExistNum(seat, size, 6) || ExistNum(seat, size, 7)) {
        ++ret;
    }
    if (ret == 2 && !ExistNum(seat, size, 4) && !ExistNum(seat, size, 5) && !ExistNum(seat, size, 6) && !ExistNum(seat, size, 7)) {
        ret = 1;
    }
    printf("%d\n", ret);
    return ret;
}

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize){
    int ret = n << 1;
    if (reservedSeats == NULL || reservedSeatsSize == 0 || reservedSeatsColSize[0] == 0) {
        return ret;
    }

    qsort(reservedSeats, reservedSeatsSize, sizeof(reservedSeats[0]), Cmp);
    int i, j;
    int seat[10];
    for (i = 0; i < reservedSeatsSize;) {
        seat[0] = reservedSeats[i][1];
        for (j = i + 1; j < reservedSeatsSize; ++j) {
            if (reservedSeats[j][0] == reservedSeats[i][0]) {
                seat[j - i] = reservedSeats[j][1];
            } else {
                break;
            }
        }
        ret -= DecreaseFamily(seat, j - i);
        i = j;
    }

    return ret;
}

```