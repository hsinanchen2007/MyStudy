### 解题思路
直接看代码

特殊值和边界值，需要关注

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_BUF 32
#define NUM_INVALID 0xFFFFFFFF
char* GetResContent(int start, int end)
{
    char buf[MAX_BUF] = {0};

    if (start == end) {
        sprintf(buf, "%d", start);
    } else {
        sprintf(buf, "%d->%d", start, end);
    }

    int len = 0;
    for (int i = 0; i < MAX_BUF; i++) {
        if (buf[i] == 0) {
            break;
        } else {
            len++;
        }
    }   
    
    char* content = (char*)malloc(sizeof(char) * (len + 1));
    memset(content, 0, sizeof(char) * (len + 1));
    memcpy(content, buf, sizeof(char) * len);
    
    return content;
}
char** UpdateRes(char **res, int len, int start, int end)
{
    if (res == NULL) {
        res = (char**)malloc(sizeof(char*));
        res[0] = GetResContent(start, end);
    } else {
        res = (char**)realloc(res, sizeof(char*) * (len + 1));
        res[len] = GetResContent(start, end);
    }

    return res;
}
char ** findMissingRanges(int* nums, int numsSize, int lower, int upper, int* returnSize){
    int i;
    long num;
    long start;
    int len;
    int **res = NULL;

    if (nums == NULL) {
        *returnSize = 0;
        return NULL;
    }   

    if (numsSize == 0) {
        res = UpdateRes(res, len, lower, upper);
        len++;
        *returnSize = len;
        return res;
    } 

    len = 0;
    if ((nums[0] > upper) || (nums[numsSize - 1] < lower)) {
        res = UpdateRes(res, len, lower, upper);
        len++;
        *returnSize = len;
        return res;
    }

    if (nums[0] > lower) {
        res = UpdateRes(res, len, lower, nums[0] - 1);
        len++;
    }

    start = NUM_INVALID;
    for (i = 0; i < numsSize; i++) {
        num = nums[i];
        if (start == NUM_INVALID) {
            start = (int)num;
        } else {
            if (num - 1 >= start + 1) {
                res = UpdateRes(res, len, start + 1, num - 1);
                len++;
            }
            start = num;
        }
    }

    if (nums[numsSize - 1] < upper) {
        res = UpdateRes(res, len, nums[numsSize - 1] + 1, upper);
        len++;
    }

    *returnSize = len;
    return res;
}
```