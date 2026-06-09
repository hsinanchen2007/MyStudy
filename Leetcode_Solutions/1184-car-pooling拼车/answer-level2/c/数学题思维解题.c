把此题转换成一个数组，每个站为数组中的一项，每次只需要把遍历到起始到结束的人都加到每个站就可以了，加的时候判断每个站的人数，不能超过车的容量就可以了
bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    int i, j, num, start, end;
    int bak = 0;
    int a[1000] = {0};

    *tripsColSize = 3;

    for (i = 0;i < tripsSize; i ++) {
        num = trips[i][0];
        start = trips[i][1];
        end = trips[i][2];
        for (j = start; j < end; j ++) {
            a[j] = a[j] + num;
            if (a[j] > capacity) {
                return false;
            }
        }
    }
    return true;
}