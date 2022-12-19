自己想到了欧拉回路问题，但是对于那个度为1的点如何处理一直没想通，参考了pwrliang的题解思路写的，看到C代码较少，写了一个供大家参考。
由于需要生成邻接表，直接用插入排序效率最高。
保存结果直接用链表向表头插入，处理起来比较容易，全处理完再将链表转换成最终的char**即可。
```
typedef struct node {
    char name[4];
    struct node *next;
} Node;
Node g_map[20000];
Node g_result;
void Init()
{
    int i;
    for (i = 0; i < 1000; i++) {
        memset(g_map[i].name, 0, sizeof(char)*4);
        g_map[i].next = NULL;
    }
}
int Hash(char *s, int len)
{
    int i;
    int sum = 0;
    for (i = 0; i < len; i++) {
        sum = sum * 27 + (s[i] - 'A'); /* 一定不会冲突 */
    }
    return sum;
}
void MakeGraph(char ***tickets, int ticketsSize)
{
    int i, h;
    Node *new = NULL;
    Node *curr = NULL;
    Node *pre = NULL;
    for (i = 0; i < ticketsSize; i++) {
        h = Hash(tickets[i][0], 3);
        /* printf("MakeGraph: %d, =%s\n", h, tickets[i][0]); */
        strcpy(g_map[h].name, tickets[i][0]);
        if (g_map[h].next == NULL) {
            new = calloc(1, sizeof(Node));
            strcpy(new->name, tickets[i][1]);
            new->next = NULL;
            g_map[h].next = new;
        } else {
            /* 插入排序 */
            pre = &g_map[h];
            curr = g_map[h].next;
            while ((curr != NULL) && (strcmp(curr->name, tickets[i][1]) < 0)) {
                pre = curr;
                curr = curr->next;
            }
            new = calloc(1, sizeof(Node));
            strcpy(new->name, tickets[i][1]);
            new->next = curr;
            pre->next = new;
        }
    }
}
void AddResult(char *s)
{
    Node *res = calloc(1, sizeof(Node));
    strcpy(res->name, s);
    res->next = g_result.next;
    g_result.next = res;
}
void Dfs(char *s)
{
    int h = Hash(s, 3);
    char name[4] = {0};
    Node *vis = NULL;
    while (g_map[h].next != NULL) {
        vis = g_map[h].next;
        g_map[h].next = vis->next;
        strcpy(name, vis->name);
        free(vis); /* 先删除再搜，防止环 */
        Dfs(name);
    }
    if (g_map[h].next == NULL) {
        AddResult(s);
    }
}
char ** findItinerary(char *** tickets, int ticketsSize, int* ticketsColSize, int* returnSize){
    int cnt = 0;
    char a[4] = "JFK";
    char **res = calloc(26*26*26, sizeof(char*));
    Node *tmp = NULL;
    g_result.next = NULL;
    if ((tickets == NULL) || (ticketsSize == 0)) {
        *returnSize = 0;
        return NULL;
    }
    Init();
    MakeGraph(tickets, ticketsSize);
    Dfs(a);
    while (g_result.next != NULL) {
        tmp = g_result.next;
        res[cnt] = calloc(4, sizeof(char));
        strcpy(res[cnt], g_result.next->name);
        cnt++;
        g_result.next = tmp->next;
        free(tmp);
    }
    /* map和result链表内存处理时已释放，无需再释放 */
    *returnSize = cnt;
    return res;
}
```
