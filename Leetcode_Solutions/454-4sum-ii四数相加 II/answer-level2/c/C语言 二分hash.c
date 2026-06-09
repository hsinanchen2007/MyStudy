### 解题思路
单用hash除了性能案例，其他都可以过
想过性能案例就产生中间的sum hash结果，不然sum量级是在是太大了...
![image.png](https://pic.leetcode-cn.com/66ba9c39d67b9c7f0c0b39bf50ab304f55a059bac45e8d19ab0d10d517e6e6de-image.png)

### 代码

```c
#define MY_NUM_2 2
#define MY_NUM_4 4
#define MY_MAX_SIZE 250000
typedef struct {
    int n;
    int cnt;
    UT_hash_handle hh;
} MyNum;
typedef struct {
    const char *name;
    MyNum nums[MY_MAX_SIZE];
    int cnt;
    int size;
    MyNum *hh_nums;
} MyArr;

typedef struct {
    MyArr arr[MY_NUM_4];
    MyArr sumArr[MY_NUM_2];
} MyStatus;

MyStatus g_status = { 0 };
void aFree(MyArr *a)
{
    HASH_CLEAR(hh, a->hh_nums);
    a->hh_nums = NULL;
    return;
}
void aInit(MyArr *a, const char *name, int size) {
    int i;
    a->name = name;
    a->size = size;
    a->cnt = 0;
    a->hh_nums = NULL;
}
void aAdd(MyArr *a, int n, int cnt)
{
    MyNum *item = NULL;
    if(a->cnt == a->size) {
        printf("%s aAdd buffer is not enough\n", a->name);
        return;
    }
    HASH_FIND_INT(a->hh_nums, &n, item);
    if (item != NULL) {
        item->cnt += cnt;
        return;
    }
    a->nums[a->cnt].n = n;
    a->nums[a->cnt].cnt = cnt;
    HASH_ADD_INT(a->hh_nums, n, (&a->nums[a->cnt]));
    a->cnt++;
    return;
}
void sFree(MyStatus *s)
{
    int i;
    for (i = 0; i < MY_NUM_4; i++) {
        aFree(&s->arr[i]);
    }
    for (i = 0; i < MY_NUM_2; i++) {
        aFree(&s->sumArr[i]);
    }
    return;
}
void sProcSum(MyArr *a1, MyArr *a2, MyArr *as)
{
    MyNum *n1;
    MyNum *t1;
    MyNum *n2;
    MyNum *t2;
    MyNum *sumItem;
    int sum;
    int cnt;
    HASH_ITER(hh, a1->hh_nums, n1, t1) {
        HASH_ITER(hh, a2->hh_nums, n2, t2) {
            sum = n1->n + n2->n;
            cnt = n1->cnt * n2->cnt;
            sumItem = NULL;
            HASH_FIND_INT(as->hh_nums, &sum, sumItem);
            if (sumItem != NULL) {
                sumItem->cnt += cnt;
            } else {
                aAdd(as, sum, cnt);
            }
        }
    }
}
void sInit(MyStatus *s, int inx, const char *name, int *arr, int arrSize)
{
    int i;
    aInit(&s->arr[inx], name, MY_MAX_SIZE);
    for (i = 0; i < arrSize; i++) {
        aAdd(&s->arr[inx], arr[i], 1);
    }
}
int proc(MyStatus *s, int sum)
{
    MyNum *s1;
    MyNum *t1;
    MyNum *s2;
    MyNum *t2;
    int left;
    int total = 0;
    HASH_ITER(hh, s->sumArr[0].hh_nums, s1, t1) {
        left = sum - s1->n;
        HASH_FIND_INT(s->sumArr[1].hh_nums, &left, s2);
        if (s2 != NULL) {
            total += s1->cnt * s2->cnt;
        }
    }
    return total;
}

int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize){
    int rlt;
    MyStatus *s = &g_status;
    sInit(s, 0, "A", A, ASize);
    sInit(s, 1, "B", B, BSize);
    sInit(s, 2, "C", C, CSize);
    sInit(s, 3, "D", D, DSize);
    aInit(&s->sumArr[0], "A+B", MY_MAX_SIZE);
    aInit(&s->sumArr[1], "C+D", MY_MAX_SIZE);
    sProcSum(&s->arr[0], &s->arr[1], &s->sumArr[0]);
    sProcSum(&s->arr[2], &s->arr[3], &s->sumArr[1]);
    rlt = proc(s, 0);
    sFree(s);
    return rlt;
}
```