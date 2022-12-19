### 解题思路
比较简单，一次通过，直接上代码

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define BUF_MAX 32
#define NUM_INVALID 0xFFFFFFFF
char* GetResContent(int start, int end)
{
    char buf[BUF_MAX] = {0};

    if (start == end) {
        sprintf(buf, "%d", start);
    } else {
        sprintf(buf, "%d->%d", start, end);
    }        

    int len = 0;
    for (int i = 0; i < BUF_MAX; i++) {
        if (buf[i] == 0) {
            break;
        } else {
            len++;
        }
    }

    char *content = (char*)malloc(sizeof(char) * (len + 1));
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
char ** summaryRanges(int* nums, int numsSize, int* returnSize){
    int i;
    long start, end;
    char**res = NULL;
    int len;

    if ((nums == NULL) || (numsSize == 0)) {
        *returnSize = 0;
        return NULL;
    }

    start = NUM_INVALID;
    end = NUM_INVALID;
    len = 0;
    for (i = 0; i < numsSize; i++) {
        if (start == NUM_INVALID) {
            start = nums[i];
            end = nums[i];
        } else {
            if (nums[i] > end + 1) {
                res = UpdateRes(res, len, start, end);
                len++;
                start = nums[i];
                end = nums[i];
            } else {
                end = nums[i];
            }
        }
    }

    res = UpdateRes(res, len, start, end);
    len++;

    *returnSize = len;
    return res;
}   
```