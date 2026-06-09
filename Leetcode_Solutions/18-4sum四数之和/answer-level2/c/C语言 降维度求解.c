### 解题思路
4个数问题，转成3个数问题，再转成2个数问题
![image.png](https://pic.leetcode-cn.com/f0eb81483dc79c2cbc2c3852d323b42ce00703990556d657230a14d966307906-image.png)

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MY_OK 0
#define MY_FAIL (-1)

#define MY_BASE_SIZE 1024
#define MY_NUM_2 2
#define MY_NUM_3 3
#define MY_NUM_4 4
typedef struct {
    int **rlt;
    int *returnColumnSizes;
    int size;
    int cnt;
} MyRlt;
typedef struct {
    int *cur;
    int inx;
} MyStatus;
void traceNums(int* nums, int numsSize)
{
    int i;
    for (i = 0; i < numsSize; i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n");
}
void sFree(MyStatus *s)
{
    if (s->cur != NULL) {
        free(s->cur);
        s->cur = NULL;
    }
    return;
}
int sInit(MyStatus *s)
{
    s->cur = (int*)calloc(MY_NUM_4, sizeof(int));
    if (s->cur == NULL) {
        return MY_FAIL;
    }
    s->inx = 0;
    return MY_OK;
}
void rFree(MyRlt *r)
{
    if (r->rlt != NULL) {
        free(r->rlt);
        r->rlt = NULL;
    }
    if (r->returnColumnSizes != NULL) {
        free(r->returnColumnSizes);
        r->returnColumnSizes = NULL;
    }
    return;
}
int rInit(MyRlt *r)
{
    r->size = MY_BASE_SIZE;
    r->rlt = (int**)calloc(r->size, sizeof(int*));
    if (r->rlt == NULL) {
        printf("rInit r->rlt == NULL\n");
        return MY_FAIL;
    }
    r->returnColumnSizes = (int*)calloc(r->size, sizeof(int));
    if (r->returnColumnSizes == NULL) {
        printf("rInit r->returnColumnSizes == NULL\n");
        free(r->rlt);
        r->rlt = NULL;
        return MY_FAIL;
    }
    r->cnt = 0;
    return MY_OK;
}
int rAdd(MyRlt *r, MyStatus *s)
{
    if (r->cnt == r->size) {
        printf("rAdd buffer is not enough\n");
        return MY_FAIL;
    }
    r->rlt[r->cnt] = (int*)calloc(MY_NUM_4, sizeof(int));
    if (r->rlt[r->cnt] == NULL) {
        printf("rAdd r->rlt[r->cnt] == NULL\n");
        return MY_FAIL;
    }
    memcpy(r->rlt[r->cnt], s->cur, sizeof(int) * MY_NUM_4);
    r->returnColumnSizes[r->cnt] = MY_NUM_4;
    r->cnt++;
    return MY_OK;
}
void procTwo(MyRlt *r, MyStatus *s, int* nums, int numsSize, int target)
{
    int sum;
    int left, right;
    if (numsSize < MY_NUM_2) {
        return;
    }
    left = 0;
    right = numsSize - 1;
    while (left < right) {
        sum = nums[left] + nums[right];
        if (sum > target) {
            right--;
            continue;
        }
        if (sum < target) {
            left++;
            continue;
        }
        s->cur[s->inx] = nums[left];
        s->cur[s->inx+1] = nums[right];
        if (r->cnt != 0 && memcmp(r->rlt[r->cnt-1], s->cur, MY_NUM_4 * sizeof(int)) == 0) {
            left++;
            continue;
        }

        rAdd(r, s);
    }
    return;
}
void procThree(MyRlt *r, MyStatus *s, int* nums, int numsSize, int target)
{
    int i;
    if (numsSize < MY_NUM_3) {
        return;
    }
    for (i = 0; i <= numsSize - MY_NUM_3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        s->cur[s->inx] = nums[i];
        s->inx++;
        procTwo(r, s, &nums[i+1], numsSize - i - 1, target - nums[i]);
        s->inx--;
    }
}
void procFour(MyRlt *r, MyStatus *s, int* nums, int numsSize, int target)
{
    int i;
    if (nums == NULL || numsSize < MY_NUM_4) {
        return;
    }
    for (i = 0; i <= numsSize - MY_NUM_4; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        s->cur[s->inx] = nums[i];
        s->inx++;
        procThree(r, s, &nums[i+1], numsSize - i - 1, target - nums[i]);
        s->inx--;
    }
}
int cmp(const void *a, const void *b)
{
    return *(int*)a > *(int*)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int ret;
    MyRlt r;
    MyStatus s;
    ret = rInit(&r);
    ret |= sInit(&s);
    if (ret != MY_OK) {
        rFree(&r);
        sFree(&s);
        *returnSize = 0;
        return NULL;
    }
    if (nums == NULL || numsSize < MY_NUM_4) {
        *returnSize = 0;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    //traceNums(nums, numsSize);
    procFour(&r, &s, nums, numsSize, target);
    sFree(&s);
    *returnSize = r.cnt;
    *returnColumnSizes = r.returnColumnSizes;
    return r.rlt;
}
```