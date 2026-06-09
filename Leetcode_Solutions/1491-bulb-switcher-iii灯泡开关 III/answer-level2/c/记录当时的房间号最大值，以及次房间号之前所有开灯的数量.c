c题解
int numTimesAllBlue(int* light, int lightSize){
    // 记录当时的房间号最大值，以及次房间号之前所有开灯的数量
    int MaxRoomIdx, cnt, totalCnt;
    MaxRoomIdx = 0;
    cnt = 0;
    totalCnt = 0;
    for (int i = 0; i <lightSize; i++) {
        MaxRoomIdx = MaxRoomIdx > light[i] ? MaxRoomIdx : light[i];  
        cnt++;
        if (MaxRoomIdx == cnt) {
            totalCnt++;
        }
    }
    return totalCnt;
}