![5B2486FC-8FE3-4B1B-9A4E-0222AD9E98B2.jpeg](https://pic.leetcode-cn.com/d68e473a31ddd9c636b664f13d0dd875db9a7f6d0e72e01759d8be7efb7f7152-5B2486FC-8FE3-4B1B-9A4E-0222AD9E98B2.jpeg)

```
#define MAXSIZE 300

typedef struct {
    int id;
    long long int interval;
} LogSystem;

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

int g_logSystemSum = 0;
LogSystem g_logSystem[MAXSIZE];

LogSystem* logSystemCreate() {
    g_logSystemSum = 0;
    LogSystem *tmpLogSystem = (LogSystem *)malloc(sizeof(LogSystem));
    return tmpLogSystem;
}
/*
int Cmp(const void *a, const void *b)
{
    return *(long long int *)(((LogSystem *)a)->interval) - *(long long int *)(((LogSystem *)b)->interval);
}
*/
void GetTime(char * timestamp, Time *time)
{
    time->year = (timestamp[0] - '0') * 1000 + (timestamp[1] - '0') * 100 + (timestamp[2] - '0') * 10 + (timestamp[3] - '0');
    time->month = (timestamp[5] - '0') * 10 + (timestamp[6] - '0');
    time->day = (timestamp[8] - '0') * 10 + (timestamp[9] - '0');
    time->hour = (timestamp[11] - '0') * 10 + (timestamp[12] - '0');
    time->minute = (timestamp[14] - '0') * 10 + (timestamp[15] - '0');
    time->second = (timestamp[17] - '0') * 10 + (timestamp[18] - '0');
}

void logSystemPut(LogSystem* obj, int id, char * timestamp) 
{
    Time time;
    long long int interval = 0;
    GetTime(timestamp, &time);
    interval = (time.year - 1999) * 12 * 31 * 24 * 60 * 60 +  
        time.month * 31 * 24 * 60 * 60 + time.day * 24 * 60 * 60 + time.hour * 60 * 60 + time.minute * 60 + time.second;
    g_logSystem[g_logSystemSum].interval = interval;
    g_logSystem[g_logSystemSum].id = id;
    g_logSystemSum++;
    //qsort(g_logSystem, g_logSystemSum, sizeof(g_logSystem[0]), Cmp);
}

int ReturnGra(char * gra) 
{
    int graPos = 0;
    if (strcmp(gra, "Year") == 0) {
        graPos = 1;
    } else if (strcmp(gra, "Month") == 0) {
        graPos = 2;
    } else if (strcmp(gra, "Day") == 0) {
        graPos = 3;
    } else if (strcmp(gra, "Hour") == 0) {
        graPos = 4;
    } else if (strcmp(gra, "Minute") == 0) {
        graPos = 5; 
    } else if (strcmp(gra, "Second") == 0) {
        graPos = 6; 
    }

    return graPos;
}

int* logSystemRetrieve(LogSystem* obj, char * s, char * e, char * gra, int* retSize) 
{
    int graPos = 0;
    int *returnVal = (int *)malloc(MAXSIZE * sizeof(int));
    graPos = ReturnGra(gra);
    Time startTime;
    GetTime(s, &startTime);
    Time endTime;
    GetTime(e, &endTime);
    long long int startInterval = 0;
    long long int endInterval = 0;
    startInterval = (startTime.year - 1999) * 12 * 31 * 24 * 60 * 60 
                        + ((graPos >= 2) ? startTime.month * 31 * 24 * 60 * 60 : 0)
                        + ((graPos >= 3) ? startTime.day * 24 * 60 * 60 : 0)
                        + ((graPos >= 4) ? startTime.hour * 60 * 60 : 0)
                        + ((graPos >= 5) ? startTime.minute * 60 : 0)
                        + ((graPos >= 6) ? startTime.second : 0);
    endInterval = (endTime.year - 1999) * 12 * 31 * 24 * 60 * 60 
                        + ((graPos >= 2) ? endTime.month * 31 * 24 * 60 * 60 : (12 * 31 * 24 * 60 * 60) - 1)
                        + ((graPos >= 3) ? endTime.day * 24 * 60 * 60 : (31 * 24 * 60 * 60) - 1)
                        + ((graPos >= 4) ? endTime.hour * 60 * 60 : (24 * 60 * 60) - 1)
                        + ((graPos >= 5) ? endTime.minute * 60 : (60 * 60) - 1)
                        + ((graPos >= 6) ? endTime.second : (60) - 1);
    int i;
    for (i = 0; i < g_logSystemSum; i++) {
        if ((g_logSystem[i].interval >= startInterval) && (g_logSystem[i].interval <= endInterval)) {
            returnVal[*retSize] = g_logSystem[i].id;
            (*retSize)++;
        }
    }
    return returnVal;
}

void logSystemFree(LogSystem* obj) {
    free(obj);
}

/**
 * Your LogSystem struct will be instantiated and called as such:
 * LogSystem* obj = logSystemCreate();
 * logSystemPut(obj, id, timestamp);
 
 * int* param_2 = logSystemRetrieve(obj, s, e, gra, retSize);
 
 * logSystemFree(obj);
*/
```
