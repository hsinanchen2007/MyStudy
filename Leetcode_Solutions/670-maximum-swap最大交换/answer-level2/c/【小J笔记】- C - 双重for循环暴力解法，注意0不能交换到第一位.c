```
#define MAX_SIZE (100)

char g_nums[MAX_SIZE];
char g_oriNums[MAX_SIZE];
char g_nextNums[MAX_SIZE];
int maximumSwap(int num)
{
    int i;
    int j;
    int len;
    int ret;
    char c;
    if (num <= 9) {
        return num;
    }
    sprintf(g_nums, "%d", num);
    sprintf(g_oriNums, "%d", num);
    sprintf(g_nextNums, "%d", num);
    
    len = strlen(g_nums);
    for (i = 0; i <= len - 2; i++) {
        for (j = i + 1; j <= len - 1; j++) {
            strncpy(g_nextNums, g_oriNums, len + 1);
            if (i == 0) {
                if (g_nextNums[j] != '0') {
                    c = g_nextNums[i];
                    g_nextNums[i] = g_nextNums[j];
                    g_nextNums[j] = c;
                }
            } else {
                c = g_nextNums[i];
                g_nextNums[i] = g_nextNums[j];
                g_nextNums[j] = c;
            }
            if (strncmp(g_nextNums, g_nums, len + 1) > 0) {
                strncpy(g_nums, g_nextNums, len + 1);
            }
        }
    }
    ret = atoi(g_nums);
    return ret;
}
```
