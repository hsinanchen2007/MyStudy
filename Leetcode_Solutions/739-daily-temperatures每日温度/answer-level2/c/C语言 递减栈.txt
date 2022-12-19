### 解题思路
递减栈
![image.png](https://pic.leetcode-cn.com/3a74158c8bc8d93ee18dd278fb3a16ee4a19553a87faa7579bc1b1cb113c0a42-image.png)

### 代码

```c
/* *
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MY_OK 0
#define MY_FAIL (-1)

typedef struct {
    int temp;
    int inx;
} MyItem;

typedef struct {
    MyItem *sta;
    int size;
    int cnt;
} MyStack;

void trace(MyStack *s)
{
    int i;
    for (i = 0; i < s->cnt; i++) {
        printf("[%d,%d],", s->sta[i].temp, s->sta[i].inx);
    }
    printf("\n");
}
void sFree(MyStack *s)
{
    if (s->sta != NULL) {
        free(s->sta);
        s->sta = NULL;
    }
    return;
}
int sInit(MyStack *s, int size)
{
    s->size = size;
    s->sta = (MyItem *)calloc(s->size, sizeof(MyItem));
    if (s->sta == NULL) {
        printf("sInit s->sta == NULL\n");
        return MY_FAIL;
    }
    s->cnt = 0;
    return MY_OK;
}
void sPush(MyStack *s, MyItem item)
{
    if (s->cnt == s->size) {
        printf("sPush s->cnt == s->size\n");
        return;
    }
    s->sta[s->cnt] = item;
    s->cnt++;
    return;
}
void sPop(MyStack *s, MyItem *item)
{
    if (s->cnt == 0) {
        printf("sPop s->cnt == 0\n");
        return;
    }
    *item = s->sta[s->cnt - 1];
    s->cnt--;
}
void sPeek(MyStack *s, MyItem *item)
{
    if (s->cnt == 0) {
        printf("sPop s->cnt == 0\n");
        return;
    }
    *item = s->sta[s->cnt - 1];
}
bool sIsEmpty(MyStack *s)
{
    return s->cnt == 0;
}
void traceRlt(int *rlt, int size)
{
    int i;
    for (i = 0; i < size; i++) {
        printf("%d,", rlt[i]);
    }
    printf("\n");
}
int *proc(MyStack *s, int *T, int TSize, int *returnSize)
{
    int i;
    MyItem cur;
    MyItem peek;
    MyItem pop;
    int *rlt = NULL;
    if (TSize <= 0) {
        *returnSize = 0;
        return NULL;
    }
    rlt = (int *)calloc(TSize, sizeof(int));
    if (rlt == NULL) {
        return NULL;
    }
    *returnSize = TSize;
    for (i = 0; i < TSize; i++) {
        cur.temp = T[i];
        cur.inx = i;
        while (sIsEmpty(s) == false) {
            sPeek(s, &peek);
            if (cur.temp <= peek.temp) {
                break;
            }
            rlt[peek.inx] = cur.inx - peek.inx;
            sPop(s, &pop);
        }
        sPush(s, cur);
    }
    while (sIsEmpty(s) == false) {
        sPop(s, &pop);
        rlt[pop.inx] = 0;
    }
    return rlt;
}
int *dailyTemperatures(int *T, int TSize, int *returnSize)
{
    int ret;
    int *rlt = NULL;
    MyStack s;
    ret = sInit(&s, TSize);
    if (ret != MY_OK) {
        *returnSize = 0;
        return NULL;
    }
    rlt = proc(&s, T, TSize, returnSize);
    sFree(&s);
    return rlt;
}
```