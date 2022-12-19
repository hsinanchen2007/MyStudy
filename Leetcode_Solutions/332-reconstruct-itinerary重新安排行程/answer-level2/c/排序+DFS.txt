### 解题思路
1、qsort排序
2、DFS逐一比较，进出DFS关键标志置位，返回

### 代码
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define STR_LEN 4

int cmp(const void *str1, const void *str2)
{
    const char **tmp1 = *(char**)str1;
    const char **tmp2 = *(char**)str2;
    int ret = strcmp(tmp1[0], tmp2[0]);
    if (ret == 0) {
        return strcmp(tmp1[1], tmp2[1]);
    }
    return ret;
}

DFS(char ***tickets, int ticketsSize, char *start, int *flag, int *count)
{
    for (int i = 0; i < ticketsSize; i++) {
        if (strcmp(start, tickets[i][0]) == 0 && flag[i] == -1) {
            flag[i] = *count;
             (*count)++;
            char *newstart = tickets[i][1];
            DFS(tickets, ticketsSize, newstart, flag, count);
            if (*count == ticketsSize) {
                return;
            }
            (*count)--;
            flag[i]= -1;
            
        }    
    }
    return;
}

char ** findItinerary(char *** tickets, int ticketsSize, int* ticketsColSize, int* returnSize){
    *returnSize = ticketsSize + 1; 
    int flag[ticketsSize];
    for (int i = 0; i < ticketsSize; i++) {
        flag[i] = -1;
    }

    char *start = "JFK";
    char **res = (char **)malloc(sizeof(char *) * (ticketsSize + 1));
    res[0] = (char *)malloc(sizeof(char) * STR_LEN);
    strncpy(res[0], start, STR_LEN);
    qsort(tickets, ticketsSize, sizeof(tickets[0]), cmp);

    int count = 0;
    DFS(tickets, ticketsSize, start, flag, &count);

    for (int j = 0; j < ticketsSize; j++) {
        res[flag[j] + 1] = (char *)malloc(sizeof(char) * STR_LEN);
        strncpy(res[flag[j] + 1], tickets[j][1], STR_LEN);
    }

    return res;
}
```