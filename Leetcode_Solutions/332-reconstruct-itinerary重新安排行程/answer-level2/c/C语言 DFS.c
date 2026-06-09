### 解题思路
1.字符数组排序，减少时间复杂度。
2.dfs 用g_flag标记飞行次序，用count判断出口。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define STR_LEN 4
int g_flag[300];
 void dfs(char *** tickets, int ticketsSize, char *** res, char *start, int *count)
 {  //遍历飞机票
    for (int i = 0; i < ticketsSize; i++) {
        if (g_flag[i] == 0 && strcmp(start, tickets[i][0]) == 0) {//找到目的地
            (*count)++;
            //printf("#####%d %s\n", *count, start);
            g_flag[i] = *count;
            char *newStart = tickets[i][1];
            
            (*res)[(*count)] = (char*)calloc(STR_LEN, sizeof(char));
            //将目的地加到结果数组中
            strncpy((*res)[(*count)], newStart, STR_LEN);
            //遍历下个目的地
            dfs(tickets, ticketsSize, res, newStart, count);
            //当结果数组满了，则返回。
            if (*count  == ticketsSize ) {
                return;
            }
            //不符合则回溯
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

    dfs(tickets, ticketsSize, &res, start, &count);

    res[0] = (char*)calloc(STR_LEN, sizeof(char));
    strncpy(res[0], start, STR_LEN);

    return res;
}
