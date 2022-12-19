### 解题思路
此处撰写解题思路
DFS
1、按照起始机场名字排序，便于后续高效收索；
2、HASH存储，KEY为起始机场名字，VALUE两个，一个是该起始机场在排序后数组中的起始位置，一个是起始机场出现的次数；
3、从JKF位置出发，DFS按照顺序遍历每张机票，如果可以遍历完，就返回答案。

char **DFS_findIt(char ***tickets, int *order, int size)
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX 1000
#define AIRPLANLEN 4
bool g_valid[MAX];
int g_ticketsSize;
typedef struct {
    char name[AIRPLANLEN];
    int index;
    int cnt;
    UT_hash_handle hh;
}Hash_Name;
Hash_Name *g_head;
int Cmp(const void *a, const void *b)
{
    char **fa = *(char ***)a;
    char **fb = *(char ***)b;
    if (strcmp(fa[0], fb[0]) == 0) {
        return strcmp(fa[1], fb[1]);
    } else {
        return strcmp(fa[0], fb[0]);
    }
}
char **DFS_findIt(char ***tickets, int *order, int size)
{
    if (size >= g_ticketsSize - 1) {
        char **retIt = malloc((g_ticketsSize + 1) * sizeof(char *));
        retIt[0] = (char *)malloc(sizeof(char) * 4);
        strcpy(retIt[0], tickets[order[0]][0]);
        for (int i = 1; i < g_ticketsSize + 1; i++) {
            retIt[i] = (char *)malloc(sizeof(char) * 4);
            strcpy(retIt[i], tickets[order[i - 1]][1]);
        }
        return retIt;
    }
    int index = order[size];
    size++;
    Hash_Name *tmp = NULL;
    HASH_FIND_STR(g_head, tickets[index][1], tmp);
    if (tmp == NULL) {
        return NULL;
    }
    for (int i = tmp->index; i < (tmp->cnt + tmp->index); i++) {
        if (g_valid[i] == 1) {
            continue;
        }
        order[size] = i;
        g_valid[i] = 1;
        char **retIt = DFS_findIt(tickets, order, size);
        if (retIt != NULL) {
            return retIt;
        }
        g_valid[i] = 0;
    }
    return NULL;
}
void AddHash(char *** tickets)
{
    Hash_Name *tmp = NULL;
    for (int i = 0; i < g_ticketsSize; i++) {
        HASH_FIND_STR(g_head, tickets[i][0], tmp);
        if (tmp != NULL) {
            tmp->cnt++;
        } else {
            tmp = (Hash_Name *)malloc(sizeof(Hash_Name));
            strcpy(tmp->name, tickets[i][0]);
            tmp->cnt = 1;
            tmp->index = i;
            HASH_ADD_STR(g_head, name, tmp);
        }
    }
}
void FreeHash()
{
    Hash_Name *tmp, *current_user;
    HASH_ITER(hh, g_head, current_user, tmp)
    {
        HASH_DEL(g_head,current_user);
        free(current_user);
    }
}
void PrnHash()
{
    Hash_Name *tmp = NULL;
	for (tmp = g_head; tmp != NULL; tmp = tmp->hh.next) { 
	    printf("name is %s index is %d, cnt is %d\n", tmp->name, tmp->index, tmp->cnt);
	}
}
char ** findItinerary(char *** tickets, int ticketsSize, int* ticketsColSize, int* returnSize)
{
    qsort(tickets, ticketsSize, sizeof(char **), Cmp);
    memset(g_valid, 0, sizeof(g_valid));
    g_ticketsSize = ticketsSize;
    AddHash(tickets);
    PrnHash();
    Hash_Name *tmp = NULL;
    HASH_FIND_STR(g_head, "JFK", tmp);
    if (tmp == NULL) {
        *returnSize = 0;
        return NULL;
    }
    char **retIt;
    for (int i = tmp->index; i < (tmp->index + tmp->cnt); i++) {
        int order[MAX] = {0};
        order[0] = i;
        g_valid[i] = 1;
        retIt = DFS_findIt(tickets, order, 0);
        if (retIt != NULL) {
            break;
        }
        g_valid[i] = 0;
    }
    FreeHash();
    *returnSize = ticketsSize + 1;
    return retIt;
}
```