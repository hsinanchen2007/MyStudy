- 对于时间的判断，小时数和分钟数要分开判断，不能整体判断0<=time<=2359,否则会有19:60这种用例错误。
```
#define MAX_SIZE (10)
#define TRUE (1)
#define FALSE (0)
#define MAX(a,b) ((a>b)?(a):(b))

char g_time[MAX_SIZE];
char g_hour[MAX_SIZE];
char g_minute[MAX_SIZE];
int g_visit[MAX_SIZE];
int g_maxTimeRet[MAX_SIZE];
int g_maxTime;

void Dfs(int *A, int ASize, int step)
{
    int i;
    int hour;
    int minute;
    int time;
    if (step == 4) {        
        g_hour[0] = g_time[0];
        g_hour[1] = g_time[1];
        g_hour[2] = '\0';
        g_minute[0] = g_time[2];
        g_minute[1] = g_time[3];
        g_minute[2] = '\0';
        hour = atoi(g_hour);
        minute = atoi(g_minute);
        time = atoi(g_time);
        if ((hour >= 0) && (hour <= 23) && (minute >= 0) && (minute <= 59)) {
            g_maxTime = MAX(g_maxTime, time);
        }
        //printf("%d\n", time);
        return;
    }
    for (i = 0; i < ASize; i++) {
        if (g_visit[i] == FALSE) {
            g_visit[i] = TRUE;
            g_time[step] = A[i] + '0';
            Dfs(A, ASize, step + 1);
            g_visit[i] = FALSE;
        }
    }
}

char * largestTimeFromDigits(int* A, int ASize)
{
    int i,j;
    int step = 0;  
    int len;
    char maxTimeRet[MAX_SIZE];  
    g_maxTime = -1;
    Dfs(A, ASize, step);
    //printf("maxTime = %d\n", g_maxTime);
    if (g_maxTime == -1) {
        return "";
    }
    sprintf(maxTimeRet, "%d", g_maxTime);   
    len = strlen(maxTimeRet);
    if (len == 1) {
        return "00:00"; 
    } else if (len == 3) {
        sprintf(g_maxTimeRet, "0%c:%c%c", maxTimeRet[0], maxTimeRet[1], maxTimeRet[2]); 
    }  else {
        sprintf(g_maxTimeRet, "%c%c:%c%c", maxTimeRet[0], maxTimeRet[1], maxTimeRet[2], maxTimeRet[3]); 
    }
    return g_maxTimeRet;
}
```
