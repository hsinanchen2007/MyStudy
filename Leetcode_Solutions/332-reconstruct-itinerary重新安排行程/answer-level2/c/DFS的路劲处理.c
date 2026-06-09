该题首先想到的是将我们的字符串站按照站名排序，转换成对应的站名索引，这样如果是通过C++的hash应该能够快速的实现，但是在C语言中没有相关的手段快速转换，对于站名的转换这一块需要大量的时间，且对路劲的处理效果效果作用不大。

既然要求按照最小的字母序输出对应的路径，那么可以尝试先对机票进行一次字母序的排序，然后根据起始站找到可用的机票范围，根据字母序选择可能的下一个组合，这样按序的搜索就能找到最小的字符序，基本的思路还是参照DFS。

DFS中实现类似的回溯处理。

```
#define STARTSTATION   "JFK"
int CheckParam(char *** tickets, int ticketsSize, int* ticketsColSize, int* returnSize)
{
    if (tickets == NULL || ticketsSize <= 0 || ticketsColSize == NULL || returnSize == NULL) {
        if (returnSize != NULL) {
            *returnSize = 0;
        }

        return -1;
    }

    *returnSize = 0;
    return 0;
}

int ticketCmp(const void *a, const void *b)
{
    char **a1 = *(char ***)a;
    char **b1 = *(char ***)b;

    int cmp = strcmp(a1[0], b1[0]);
    if (cmp == 0) {
        return strcmp(a1[1], b1[1]);
    }

    return cmp;
}

void TicketRange(char ***tickets, int ticketsSize, char *start, int *startIndex, int *endIndex)
{
    int s = -1;
    for (int i = 0; i < ticketsSize; ++i) {
        if (strcmp(tickets[i][0], start) == 0) {
            if (s == -1) {
                *startIndex = i;
                s = 1;
            }

            *endIndex = i;
        }
    }

    return;
}

void DFS(char ***tickets, int ticketsSize, char *mark, int *stack, int *top, int i)
{
    mark[i] = 1; //mark标记对应的票已访问
    stack[*top] = i;
    *top = *top + 1; 

    if (*top == ticketsSize) { //所有的票务均已访问
        return;
    }

    char *to = tickets[i][1];
    int start = 0;
    int end = 0;

    TicketRange(tickets, ticketsSize, to, &start, &end);
    for (int j = start; j <= end; ++j) {
        if (mark[j] == 0) {
            DFS(tickets, ticketsSize, mark, stack, top, j);
            if (*top == ticketsSize) {
                return;
            }
        }
    }

    mark[i] = 0;  //该票回退
    *top = *top - 1; //访问的票数减少，无需入栈
}

char **getPath(char *** tickets, int ticketsSize, int *stack, int* returnSize)
{
    char **path = (char **)malloc(sizeof(char *) * (ticketsSize + 1));
    int cnt = 0;
    for (int i = 0; i < ticketsSize; ++i) {
        path[cnt++] = tickets[stack[i]][0];
    }

    path[cnt++] = tickets[stack[ticketsSize - 1]][1];

    *returnSize = cnt;
    return path;
}

char ** findItinerary(char *** tickets, int ticketsSize, int* ticketsColSize, int* returnSize)
{
    if (CheckParam(tickets, ticketsSize, ticketsColSize, returnSize)) {
        return NULL;
    }

    qsort(tickets, ticketsSize, sizeof(char ***), ticketCmp);
    char *mark = (char *)malloc(sizeof(char) * ticketsSize);
    memset(mark, 0, sizeof(char) * ticketsSize);
    int *stack = (int *)malloc(sizeof(int *) * ticketsSize);
    int top = 0;

    int start;
    int end;
    char **path = NULL;

    TicketRange(tickets, ticketsSize, STARTSTATION, &start, &end);
    for (int i = start; i <= end; ++i) {
        if (mark[i] == 0) {
            DFS(tickets, ticketsSize, mark, stack, &top, i);
        }

        if (top == ticketsSize) {
            path = getPath(tickets, ticketsSize, stack, returnSize);
            break;
        }
    }

    free(mark);
    free(stack);

    return path;
}
```

