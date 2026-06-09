### 解题思路
此处撰写解题思路

### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findLongestSubarray(char** array, int arraySize, int* returnSize){
   if (arraySize <= 1) {
        *returnSize = 0;
        return NULL;
    }

    int i;
    int max = 0;
    int sum = 0;
    int start = 0;
    int end = 0;
    int hash[200000];
    int idx = 0;

    memset((void*)hash, 0xFFFF, sizeof(hash));

    for (i = 0; i < arraySize; i++) {
        if (array[i][0]>= '0' && array[i][0] <= '9') {
            sum += 1;
        } else {
            sum += -1;
        }

        // hash表对应位置为-1，说明是第一次出现该sum值
        // hash表不初始化为0，是因为array第一个参数的sum要么是1，要么是-1，对应的位置为0，下次再出1或-1时，此处如果判断是否为0，那么会重新更新1或-1出现的位置
        if (hash[sum + arraySize] == -1) {
            hash[sum + arraySize] = i;
        } else {    // 否则不是第一次出现，计算当前sum值开始和第一次出现sum值中间数字和字母个数总和
            if ((i - hash[sum + arraySize]) > (end - start)) {
                start = hash[sum + arraySize];
                end = i;
            }

            if (sum == 0 && (i + 1) > (end - start)) {
                start = 0;
                end = i;
            }
        }

        // 如果当前总和为0，说明从第一个数开始到当前数为止，字符和数字个数相等
        if (sum == 0) {
            max = i + 1;
        }

        if (max > (end - start)) {
            start = -1;
            end = i;
        } else {
            max = (end - start);
        }
    }


    if (max == 0) {
        *returnSize = 0;
        return NULL;
    }

    char **rlt = (char **)malloc(sizeof(char*) * (end - start));
    for (i = start + 1; i <= end; i++) {
        rlt[idx++] = array[i];
    }
    *returnSize = idx;

    return rlt;
}


```