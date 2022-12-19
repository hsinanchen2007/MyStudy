### 解题思路
结果是惨了点，算是个解法吧
我猜大家都是边遍历，边计算的，这边是先遍历，后面统一计算，所以性能和内存损耗都比较大
1、排序
2、通过hash，记录每个num需要移动的个数
3、找空档移动（这个需要记录最后一个空档，以提高性能）
![image.png](https://pic.leetcode-cn.com/6569c0283904e9fb1ca5ccb858f5e38eda95e96241f2919dbf752788d54d9434-image.png)

### 代码

```c
#define MY_OK 0
#define MY_FAIL (-1)

#define MY_BASE_SIZE 50000
typedef struct {
    int num;
    int need_move;
    UT_hash_handle hh;
} MyNum;
typedef struct {
    MyNum *nums;
    int size;
    int cnt;
    MyNum *hh_nums;
    int rlt;
    int last_target;
} MyStatus;
void sTrace(MyStatus *s)
{
    int cnt;
    MyNum *cur = NULL;
    MyNum *tmp = NULL;
    printf("cnt = %d, hash_cnt = %d\n", s->cnt, HASH_CNT(hh, s->hh_nums));
    HASH_ITER(hh, s->hh_nums, cur, tmp) {
        printf("num = %d, need_move = %d\n", cur->num, cur->need_move);
    }
    printf("\n");
}
void sFree(MyStatus *s)
{
    HASH_CLEAR(hh, s->hh_nums);
    if (s->nums != NULL) {
        free(s->nums);
        s->nums = NULL;
    }
    return;
}
int sInit(MyStatus *s)
{
    s->size = MY_BASE_SIZE;
    s->nums = (MyNum*)calloc(s->size, sizeof(MyNum));
    if (s->nums == NULL) {
        return MY_FAIL;
    }
    s->cnt = 0;
    s->hh_nums = NULL;
    s->rlt = 0;
    return MY_OK;
}
void sAdd(MyStatus *s, int num)
{
    MyNum *cur = NULL;
    HASH_FIND_INT(s->hh_nums, &num, cur);
    if (cur != NULL) {
        cur->need_move++;
        return;
    }
    if (s->cnt == s->size) {
        printf("sAdd buffer is not enough\n");
        return;
    }
    s->nums[s->cnt].num = num;
    s->nums[s->cnt].need_move = 0;
    HASH_ADD_INT(s->hh_nums, num, (&s->nums[s->cnt]));
    s->cnt++;
    return;
}
int findTarget(MyStatus *s, int target_min)
{
    int target;
    MyNum *num = NULL;
    target = target_min;
    while (1) {
        HASH_FIND_INT(s->hh_nums, &target, num);
        if (num == NULL) {
            break;
        }
        target++;
    }
    return target;
}
void proc(MyStatus *s, int* A, int ASize)
{
    int i;
    int target;
    int step;
    MyNum *cur = NULL;
    MyNum *tmp = NULL;
    s->last_target = INT_MIN;
    HASH_ITER(hh, s->hh_nums, cur, tmp) {
        if (s->last_target < cur->num + 1) {
            s->last_target = cur->num + 1;
        }
        for (i = 0; i < cur->need_move; i++) {
            s->last_target = findTarget(s, s->last_target);
            step = s->last_target - cur->num;
            sAdd(s, s->last_target);
            s->rlt += step;
            //printf("num:%d, target:%d, step:%d, rlt:%d\n", cur->num, target, step, s->rlt);
            s->last_target++;
        } 
    }
    return;
}
int cmp(const void *a, const void *b)
{
    return *(int*)a > *(int*)b;
}
int minIncrementForUnique(int* A, int ASize){
    int ret;
    int i;
    MyStatus s = { 0 };
    if (ASize <= 1 || A == NULL) {
        return 0;
    }
    ret = sInit(&s);
    if (ret != MY_OK) {
        return 0;
    }
    qsort(A, ASize, sizeof(int), cmp);
    for (i = 0; i < ASize; i++) {
        sAdd(&s, A[i]);
    }
    //sTrace(&s);
    proc(&s, A, ASize);
    ret = s.rlt;
    sFree(&s);
    return ret;
}
```