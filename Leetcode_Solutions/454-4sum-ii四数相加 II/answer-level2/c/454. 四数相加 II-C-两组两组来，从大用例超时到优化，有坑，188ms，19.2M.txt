### 解题思路

执行用时：188 ms
内存消耗：19.2 MB

思路是看大佬们的，A和B的和作为一个组，C和D的和作为一个组，然后找到A+B = -(C+D)的情况。
所以一开始是这么写的：（最大的最后一个用例过不了，会超时）

C语言没有方便的数据结构去保存每个结果出现的次数，所以我想是每一个结果都存在数组里，
然后进行排序，用bsearch方便的找到dict中是否有想要的结果，
因此此时数组是有序的，但是bsearch返回的找到结果的位置是不确定的，
所以首先，用【这里注意：指针的减法可以得到元素个数，不需要除以sizeof(int)】
```
int nowIndex = (tempIndex - dict);
```
来得到找到的元素的位置，然后分别从它的前和后去找到和它数值相等的结果，计数，这就是我们结果的数量。
但是这样做，最后一个大用例会超时，先看看这段代码，后面我想到一个优化的方法。

```
int Compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize){
    if (A == NULL || B == NULL || C == NULL || D == NULL || ASize == 0) {
        return 0;
    }

    int *dict = (int *)malloc(sizeof(int) * ASize * BSize);
    int dictIndex = 0;
    memset(dict, 0, sizeof(int) * ASize * BSize);

    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < BSize; j++) {
            dict[dictIndex++] = A[i] + B[j];
        }
    }
    qsort(dict, ASize * BSize, sizeof(int), Compare);

    int res = 0;
    for (int i = 0; i < CSize; i++) {
        for (int j = 0; j < DSize; j++) {
            int temp = -(C[i] + D[j]);
            int *tempIndex = bsearch(&temp, dict, ASize * BSize, sizeof(int), Compare);
            if (tempIndex != NULL) {
                res++;
                int nowIndex = (tempIndex - dict);
                int tempNow = nowIndex - 1;
                while(tempNow >= 0) {
                    if (dict[tempNow] == temp) {
                        res++;
                    }else {
                        break;
                    }
                    tempNow--;
                }
                tempNow = nowIndex + 1;
                while(tempNow < ASize * BSize) {
                    if(dict[tempNow] == temp) {
                        res++;
                    }else {
                        break;
                    }
                    tempNow++;
                }         
            }
        }
    }

    return res;
}
```


然后就是这个用例太大了，肯定超时，怎么才能过，于是根据上面数组的左右找的一个过程，想到了这么一种优化的方法：
1. dict先排序
2. C 和 D的相加结果的负数，也就是-(C+D)也放进一个数组里，我们称它为sum
3. 对dict和sum都排序
4. 现在问题就转换成了：对于sum的每一个元素，在dict中找到和它相等的结果的数量，最后相加
5. 现在转换成了一个这样的问题后，怎么找：

dict和sum都是有序数组，所以我决定采用双指针的办法去找。
对于sum，每次取一个元素，因为存在重复的可能（这里的重复都是计数的，因为每一种都代表C/D是不同的位置）
对于这个元素，先向右移动，直到与前面的元素不重复。
拿到第一个数据now的所有数量，记为repeatSize。

在dict里面寻找，从0开始。
如果，dict目前的数字，比now要大，那么再怎么往后找，dict里面的数据会越来越大，不可能和now相等，所以直接break掉。
那么这时候dictRepate就是0.
我们返回的是res += (repeatSize * dictRepate);这一趟是个0，也就是对于now，没有结果。
如果比now 小，那就往右移动dict。
如果相等，就对dictRepate++，继续移动。
最后，dictRepate就记录了在dict中，与now相等的元素的个数。
我们把结果加到res上。

这时候，最关键的一步优化来了。
因为dict和sum都是有序数组，所以取下一个sum的时候，实际上我们的dictFlag不需要再从0开始。
我们从上一次取到的dict位置开始继续，这样前面的那些注定比它小的位置，根本不需要再比较一次了。

此处还有一个需要注意的坑，一个没注意的点。
本地跑很容易过了，提交怎么都不通过，会buffer over flow
尝试调试才发现这个：
  while (sumFlag < dictSize && sum[sumFlag] == now) {
        repeatSize++;
        sumFlag++;
        continue;
}
重点就是加入这个条件sumFlag < dictSize；
因为sumFlag会++，在这个过程中它可能超过dictSize的限制，所以必须在前面加入这个条件，再次判断一下


### 代码

```c
int Compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize)
{
    if (A == NULL || B == NULL || C == NULL || D == NULL || ASize == 0) {
        return 0;
    }

    int dictSize = ASize * BSize;
    int *dict = (int *)malloc(sizeof(int) * dictSize);
    int dictIndex = 0;
    memset(dict, 0, sizeof(int) * dictSize);

    int *sum = (int *)malloc(sizeof(int) * dictSize);
    int sumIndex = 0;
    memset(sum, 0, sizeof(int) * dictSize);

    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < BSize; j++) {
            dict[dictIndex++] = A[i] + B[j];
        }
    }
    qsort(dict, dictSize, sizeof(int), Compare);

    for (int i = 0; i < CSize; i++) {
        for (int j = 0; j < DSize; j++) {
            int temp = -(C[i] + D[j]);
            sum[sumIndex++] = temp;
        }
    }
    qsort(sum, dictSize, sizeof(int), Compare);

    int res = 0;
    int dictFlag = 0;
    int sumFlag = 0;

    while (sumFlag < dictSize) {
        int repeatSize = 0;
        int dictRepate = 0;
        int now = sum[sumFlag];
        while (sumFlag < dictSize && sum[sumFlag] == now) {
            repeatSize++;
            sumFlag++;
            continue;
        }

        while (dictFlag < dictSize) {
            if (dict[dictFlag] > now) {
                break;
            }
            if (dict[dictFlag] < now) {
                dictFlag++;
                continue;
            }
            if (dict[dictFlag] == now) {
                dictRepate++;
                dictFlag++;
                continue;
            }
        }
        res += (repeatSize * dictRepate);
    }
    return res;
}
```