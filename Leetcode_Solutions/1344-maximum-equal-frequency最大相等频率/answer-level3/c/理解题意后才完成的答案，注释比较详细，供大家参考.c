### 解题思路
满足条件的场景比较好理解，最难理解的是如何使用代码描绘这个场景


### 代码
方案一：
答案就是题目的答案，主要是理解各个条件，实际就是数组代表的是个数，一定要找到最大个数的位置，然后使用这个计算，代码参考如下：

```c
#define MIN_SORT_SIZE 3
#define MAX_ELEMENT_VAL 100001
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/* *
 * 满足条件的场景有：
 * 1：很多数据，并且每个数量只有1个，因此，随意删除即可
 * 2：全部数据相同
 * 3：很多数据，其他都是N个，只有一个是1个
 * 4：很多数据，其他都是N个，只有一个是N+1个
 *
 */
int maxEqualFreq(const int *nums, int numsSize)
{
    if (numsSize <= MIN_SORT_SIZE) {
        return numsSize;
    }

    int *eleNum = NULL;
    int *countNum = NULL;

    eleNum = malloc(MAX_ELEMENT_VAL * sizeof(int));
    countNum = malloc(MAX_ELEMENT_VAL * sizeof(int));
    if ((eleNum == NULL) || (countNum == NULL)) {
        free(eleNum);
        free(countNum);
        return 0;
    }

    memset(eleNum, 0x0, MAX_ELEMENT_VAL * sizeof(int));
    memset(countNum, 0x0, MAX_ELEMENT_VAL * sizeof(int));
    int maxCount;
    int maxLen;

    maxCount = 0;
    maxLen = 0;
    for (int index = 0; index < numsSize; index++) {
        if (nums[index] >= MAX_ELEMENT_VAL) {
            break;
        }

        int pos;
        eleNum[nums[index]]++;
        pos = eleNum[nums[index]];
        countNum[pos]++;
        countNum[pos - 1]--;
        maxCount = MAX(maxCount, pos);

        /* *
         * 1：很多数据，并且每个数量只有1个，因此，随意删除即可
         * 2：全部数据相同
         */
        if ((countNum[1] == index + 1) || (countNum[maxCount] == index + 1)) {
            maxLen = index + 1;
            continue;
        }

        /*
         * 3：很多数据，其他都是N个，只有一个是1个
         * 4：很多数据，其他都是N个，只有一个是N+1个
         */
        if ((countNum[1] == 1) && (index + 1 == countNum[maxCount] * maxCount + 1)) {
            maxLen = index + 1;
            continue;
        }

        if ((countNum[maxCount] * (maxCount) + countNum[maxCount - 1] * (maxCount - 1) == index + 1) &&
            ((countNum[maxCount] == 1))) {
            maxLen = index + 1;
            continue;
        }
    }
    free(eleNum);
    free(countNum);
    return maxLen;
}
```

方案二：
我自己写的，比较好理解，但是，超时
```
#define MIN_SORT_SIZE 3
#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

typedef struct EqualNUm {
    int val;
    int count;
} EQUALNUM;

int CompareSearch(const void *a, const void *b)
{
    int *input = (int *)a;
    int *old = (int *)b;

    return *old - *input;
}

int CompareSort(const void *a, const void *b)
{
    EQUALNUM *old = (EQUALNUM *)a;
    EQUALNUM *input = (EQUALNUM *)b;
    if (old->val != input->val) {
        return (input->val - old->val);
    }
    return (input->count - old->count);
}

bool IsSomeEleEqual(const EQUALNUM *input, int count)
{
    if (count <= 1) {
        return true;
    }

    if (count == 1 + 1) {
        if ((input[1].count == 1) || (input[0].count == 1)) {
            return true;
        }

        int diff = input[1].count - input[0].count;
        if ((diff == 1) || (diff == -1)) {
            return true;
        }
        return false;
    }

    int num;
    int compare;

    if (input[1].count == input[0].count) {
        compare = input[1].count;
    } else if (input[1].count == input[1 + 1].count) {
        compare = input[1].count;
    } else if (input[1 + 1].count == input[0].count) {
        compare = input[0].count;
    } else {
        return false;
    }

    num = 0;
    for (int index = 0; index < count; index++) {
        if (input[index].count != compare) {
            int diff = input[index].count - compare;
            if (diff == 1) {
                num++;
            } else if (input[index].count == 1) {
                num++;
            }
            else {
                return false;
            }
        }
    }
    //printf("\r\n compare=%d, num=%d, count = %d", compare, num, count);
    if (num == 1) {
        return true;
    }

    if (num != 0) {
        return false;
    }
    
    if (compare == 1) {
        return true;
    }
    return false;
}

int maxEqualFreq(const int *nums, int numsSize)
{
    if (numsSize <= MIN_SORT_SIZE) {
        return numsSize;
    }

    EQUALNUM *equalList = malloc((numsSize + 1) * sizeof(EQUALNUM));
    if (equalList == NULL) {
        return 0;
    }

    int eleNum = 0;
    int maxLen = MIN_SORT_SIZE;
    memset(equalList, 0x0, (numsSize + 1) * sizeof(EQUALNUM));
    for (int index = 0; index < numsSize; index++) {
        if (0 == index) {
            equalList[eleNum].val = nums[index];
            equalList[eleNum++].count++;
            continue;
        }

        EQUALNUM *item = NULL;
        EQUALNUM find;
        find.val = nums[index];
        item = bsearch(&find, equalList, eleNum, sizeof(equalList[0]), CompareSearch);
        if (item != NULL) {
            item->count++;
        } else {
            equalList[eleNum].val = nums[index];
            equalList[eleNum++].count++;
            if (index != numsSize - 1) {
                qsort(equalList, eleNum, sizeof(equalList[0]), CompareSort);
            }
        }
        if (IsSomeEleEqual(equalList, eleNum)) {
            maxLen = MAX(maxLen, index + 1);
        }
    }

    free(equalList);
    return maxLen;
}
```
