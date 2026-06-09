### 解题思路
C语言，使用回溯，超过双百

### 代码

```c
static int** res;
static int resLen = 0;

void BackTrace(int* times, int* tmp, int tmpLen)
{
    if (tmpLen == 4) {
        if ((tmp[0] == 2 && tmp[1] <= 3 && tmp[2] <= 5) || (tmp[0] <= 1 && tmp[2] <= 5)) {
            memcpy(res[resLen], tmp, tmpLen*sizeof(int));
            resLen++;
        }
        return ;
    }
    for (int i = 0; i < 4; i++) {
        tmp[tmpLen] = times[i];
        tmpLen++;
        BackTrace(times, tmp, tmpLen);
        tmp[tmpLen-1] = 0;
        tmpLen--;
    }
}

char * nextClosestTime(char * time){
    res = (int**)malloc(256*sizeof(int*));
    for (int i = 0; i < 256; i++) {
        res[i] = (int*)malloc(4*sizeof(int));
        memset(res[i], 0, 4*sizeof(int));
    }
    resLen = 0;
    int times[4] = {0};
    times[0] = time[0] - '0';
    times[1] = time[1] - '0';
    times[2] = time[3] - '0';
    times[3] = time[4] - '0';
    int oriHour = times[0] * 10 + times[1];
    int oriMin = times[2] * 10 + times[3];

    int min = INT_MAX;
    int* tmp = (int*)malloc(4*sizeof(int));
    memset(tmp, 0, 4*sizeof(int));
    BackTrace(times, tmp, 0);
    char* resTime = (char*)malloc(6*sizeof(char));
    memset(resTime, '\0', 6*sizeof(char)); 
    for (int i = 0; i < resLen; i++) {
        int curHour = res[i][0]*10 + res[i][1];
        int curMin = res[i][2]*10 + res[i][3];
        int width = curHour*60+curMin - (oriHour*60 + oriMin);
        if (width <= 0) {
            width += 24*60;
        }
        if (width < min) {
            min = width;
            sprintf(resTime, "%d%d:%d%d", res[i][0], res[i][1], res[i][2], res[i][3]);
        }
    }
    return resTime;
}



```