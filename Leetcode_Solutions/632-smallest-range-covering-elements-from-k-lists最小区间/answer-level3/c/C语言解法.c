一、方法一（超时），使用K个下标（代码中用pos指针数组记录）遍历

    #define MAX_NUM 10000000
    #define MIN_NUM (-10000000)

    bool Compare(int *value1, int *value2)
    {
        if (value1[1] - value1[0] < value2[1] - value2[0]) {
            return false;
        } else if (value1[1] - value1[0] == value2[1] - value2[0] && value1[0] < value2[0]) {
            return false;
        }
        //printf(" Compare [%d, %d], [%d, %d]", value1[0], value1[1], value2[0], value2[1]);
        return true;
    }

    int GetNextMinPos(int** nums, int numsSize, int *numsColSize, int *pos) {
        int i;
        int minPos = -1;
        int minNum = MAX_NUM;

        for (i = 0; i < numsSize; i++) {
            if (pos[i] >= numsColSize[i]) {
                continue;
            }
            if (minNum > nums[i][pos[i]]) {
                minNum = nums[i][pos[i]];
                minPos = i;
            }
        }

        return minPos;
    }

    int CompareNum(const void *value1, const void *value2)
    {
        return *((int *)value1) - *((int *)value2);
    }

    void GetNumCompare(int *numCompare, int numSize, int *resultCompare)
    {
        int i = 0;
        resultCompare[0] = numCompare[0];
        resultCompare[1] = numCompare[0];

        for (i = 1; i < numSize; i++) {
            if (resultCompare[0] > numCompare[i]) {
                resultCompare[0] = numCompare[i];
            }
            if (resultCompare[1] < numCompare[i]) {
                resultCompare[1] = numCompare[i];
            }
        }
    }

    /**
    * Note: The returned array must be malloced, assume caller calls free().
    */
    int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize)
    {
        int *result = (int *)malloc(2 * sizeof(int));
        int *pos = (int *)malloc(numsSize * sizeof(int));
        int i;
        int maxNum = MIN_NUM;
        int minNum = MAX_NUM;
        int nextMinPos = -1;
        int *numCompare = (int *)malloc(numsSize * sizeof(int));
        //int *numCompareSort = (int *)malloc(numsSize * sizeof(int));
        int resultCompare[2] = {0};

        (void)memset(pos, 0, numsSize * sizeof(int));

        for (i = 0; i < numsSize; i++) {
            if (pos[i] >= numsColSize[i]) {
                continue;
            }
            if (maxNum < nums[i][pos[i]]) {
                maxNum = nums[i][pos[i]];
            }
            if (minNum > nums[i][pos[i]]) {
                minNum = nums[i][pos[i]];
            }
            numCompare[i] = nums[i][pos[i]];
            pos[i]++;
        }
        result[0] = minNum;
        result[1] = maxNum;
        //resultCompare[0] = minNum;
        //resultCompare[1] = maxNum;

        nextMinPos = GetNextMinPos(nums, numsSize, numsColSize, pos);
        while (nextMinPos != -1) {
            numCompare[nextMinPos] = nums[nextMinPos][pos[nextMinPos]];
            pos[nextMinPos]++;
            //(void)memcpy(numCompareSort, numCompare, sizeof(int) * numsSize);

            /*printf("%d: ", nextMinPos);
            for (int k = 0; k < numsSize; k++) {
                printf("%d ", numCompare[k]);
            }*/

            //qsort(numCompareSort, numsSize, sizeof(int), CompareNum);
            //resultCompare[0] = numCompareSort[0];
            //resultCompare[1] = numCompareSort[numsSize - 1];
            GetNumCompare(numCompare, numsSize, resultCompare);
            //printf(" *** [%d, %d]", resultCompare[0], resultCompare[1]);
            if (Compare(result, resultCompare)) {
                //printf(" ++++ ");
                //printf("[%d, %d]", result[0], result[1]);
                result[0] = resultCompare[0];
                result[1] = resultCompare[1];
            }
            //printf(" -> [%d, %d]\n", result[0], result[1]);
            nextMinPos = GetNextMinPos(nums, numsSize, numsColSize, pos);
        }

        free(pos);
        free(numCompare);
        //free(numCompareSort);

        *returnSize = 2;
        return result;
    }

二、方法二（通过），直接把所有数组拉平后排序，就不用K个下标来遍历了

    #define MAX_NUM 10000000
    #define MIN_NUM (-10000000)

    typedef struct {
        int num;
        int pos;
    } AllNum;

    bool Compare(int *value1, int *value2)
    {
        if (value1[1] - value1[0] < value2[1] - value2[0]) {
            return false;
        } else if (value1[1] - value1[0] == value2[1] - value2[0] && value1[0] < value2[0]) {
            return false;
        }
        return true;
    }

    int CompareSort(const void *value1, const void *value2)
    {
        return ((AllNum *)value1)->num - ((AllNum *)value2)->num;
    }

    void GetNumCompare(int *numCompare, int numSize, int *resultCompare)
    {
        int i = 0;
        resultCompare[0] = numCompare[0];
        resultCompare[1] = numCompare[0];

        for (i = 1; i < numSize; i++) {
            if (resultCompare[0] > numCompare[i]) {
                resultCompare[0] = numCompare[i];
            }
            if (resultCompare[1] < numCompare[i]) {
                resultCompare[1] = numCompare[i];
            }
        }
    }

    /**
    * Note: The returned array must be malloced, assume caller calls free().
    */
    int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize)
    {
        int i, j;
        int k = 0;
        int maxNum = MIN_NUM;
        int minNum = MAX_NUM;
        int len = 0;
        int resultCompare[2] = {0};
        AllNum *allNum = NULL;
        int *result = (int *)malloc(2 * sizeof(int));
        int *numCompare = (int *)malloc(numsSize * sizeof(int));

        for (i = 0; i < numsSize; i++) {
            len += numsColSize[i];
            numCompare[i] = nums[i][0];
            if (maxNum < nums[i][0]) {
                maxNum = nums[i][0];
            }
            if (minNum > nums[i][0]) {
                minNum = nums[i][0];
            }
        }
        result[0] = minNum;
        result[1] = maxNum;
        resultCompare[0] = minNum;
        resultCompare[1] = maxNum;

        len -= numsSize;
        allNum = (int *)malloc(len * sizeof(AllNum));
        for (i = 0; i < numsSize; i++) {
            for (j = 1; j < numsColSize[i]; j++) {
                allNum[k].num = nums[i][j];
                allNum[k].pos = i;
                k++;
            }
        }

        qsort(allNum, len, sizeof(AllNum), CompareSort);
        for (i = 0; i < len; i++) {
            numCompare[allNum[i].pos] = allNum[i].num;
            GetNumCompare(numCompare, numsSize, resultCompare);
            if (Compare(result, resultCompare)) {
                result[0] = resultCompare[0];
                result[1] = resultCompare[1];
            }
        }

        free(allNum);
        free(numCompare);

        *returnSize = 2;
        return result;
    }