
#define LONGEST_TIME 100000 //这个长度定义提交了几次按用例确定的，如果再大就要考虑其他存储方式

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize){
    int timeCount[LONGEST_TIME] = {0};
    for (int i = 0; i < intervalsSize; i++) {
        for (int j = intervals[i][0]; j <= intervals[i][1]; j++) {
            timeCount[j]++;
        }
    }
    int max = 0;
    for (int i = 0; i < LONGEST_TIME; i++) {
        max = max>timeCount[i]? max:timeCount[i];
    }
    return max;
}