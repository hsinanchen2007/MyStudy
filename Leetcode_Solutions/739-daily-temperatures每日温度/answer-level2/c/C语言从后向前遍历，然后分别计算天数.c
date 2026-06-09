思路：
1、从后向前分别计算
2、排查的时候，为了提高效率，记录一下后面最大值，如果排查到最大值，则提前break

代码如下：
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *daily = NULL;
    int index;
    int index1;
    int flag;
    int curmax;
    int count;

    if (TSize == 0) {
        return NULL;
    }

    daily = (int *)malloc((TSize + 10) * sizeof(int));
    if (daily == NULL) {
        return NULL;
    }

    curmax = T[TSize - 1];
    for (index = TSize - 1; index >= 0; index--) {
        count = 0;
        flag = false;        
        for (index1 = index + 1; index1 < TSize; index1++) {
            count++;
            if (T[index1] > T[index]) {
                if (T[index1] > curmax) {
                    curmax = T[index1] ;
                }
                flag = true;
                break;
            }

            if (T[index1]  == curmax) {
                break;
            }
        }

        if (flag == true) {
            daily[index] = count;
        }
        else {
            daily[index] = 0;
        }
    }

    *returnSize = TSize;
    return daily;
}
```
