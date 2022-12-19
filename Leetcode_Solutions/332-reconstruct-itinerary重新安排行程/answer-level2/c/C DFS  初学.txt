### 解题思路
供大家参考！
1、排序 自然序
2、DFS 遍历 机票打标签
3、回读数据

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define STR_LEN 4
int g_flag[1000];
 void dfs(char *** tickets, int ticketsSize, char ** res, char *start, int *count)
 {
    for (int i = 0; i < ticketsSize; i++) {
        if (g_flag[i] == 0 && strcmp(start, tickets[i][0]) == 0) {
            (*count)++;
            //printf("#####%d %s\n", *count, start);
            g_flag[i] = *count;
            char *newStart = tickets[i][1];
            dfs(tickets, ticketsSize, res, newStart, count);
            if (*count + 1 == (ticketsSize + 1)) {
                return;
            }
            (*count)--;
            g_flag[i] = 0;
        }
    }
 }
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

char ** findItinerary(char *** tickets, int ticketsSize, int* ticketsColSize, int* returnSize){
    *returnSize = ticketsSize + 1; //
    char **res = (char**)calloc(*returnSize, sizeof(char*));
    memset(g_flag, 0, sizeof(g_flag));
    //排序 自然序
    qsort(tickets, ticketsSize, sizeof(tickets[0]), cmp);

    char *start= "JFK";
    int count = 0;

    dfs(tickets, ticketsSize, res, start, &count);

    res[0] = (char*)calloc(STR_LEN, sizeof(char));
    strncpy(res[0], start, STR_LEN);

    for(int i = 1; i < *returnSize; i++) {
        res[i] = (char*)calloc(STR_LEN, sizeof(char));
        int k = 0;
        while(k < *returnSize) {
            if(g_flag[k] == i) {
                strncpy(res[i], tickets[k][1], STR_LEN);
                break;
            }
            k++;
        }
    }

    return res;
}
```