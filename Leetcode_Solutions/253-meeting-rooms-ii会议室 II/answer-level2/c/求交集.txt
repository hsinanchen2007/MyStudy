解题思路：
先按照起始时间排序，对数据进行排序；第一个直接占用一个会议室，后续时间段如果在之前所有时间内能找到一个不想交（起始时间大于等于之前时间段终止时间）的记录，那么代表可以复用会议室；但是可能存在多个时间段自己相交但都和另一个时间段不想交的情况，例如[[0,10],[15,20],[15,18]],其中[15,20],[15,18]都与[0,10]不相交，但他们互相交集，所以定义一个一维数组，如果会议室被复用，则对应的记录置1，如果没有被用，且与当前时间段（因为记录已经排序，所以后续的不相交时间段可以复用此时间段）没有交集，则代表可复用的会议室，返回0，如果找不到符合要求的记录，代表需要新增一个会议室，返回1。

int CalMeetingRoom(int **intervals, int index, int begin, int *used)
{
    for (int i = 0; i < index; i++) {
        if ((used[i] == 0) && (begin >= intervals[i][1])) {
            used[i] = 1;
            return 0;
        }
    }
    return 1;
}

int CmpFun(const void *a, const void *b)
{
    int *ap = *(int**)a;
    int *bp = *(int**)b;

    if (ap[0] == bp[0]) {
        return ap[1] - bp[1];
    } else {
        return ap[0] - bp[0];
    }
}

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize){
    if (intervalsSize == 0) {
        return 0;
    }
    if (intervalsSize == 1) {
        return 1;
    }
    int cnt = 1;
    qsort(intervals, intervalsSize, sizeof(int*), CmpFun);
    int *used = malloc(intervalsSize * sizeof(int));
    if (used == NULL) {
        return 0;
    }
    memset(used, 0, intervalsSize * sizeof(int));

    for (int i = 1; i < intervalsSize; i++) {
        cnt += CalMeetingRoom(intervals, i, intervals[i][0], used);
    }
    free(used);
    return cnt;
}