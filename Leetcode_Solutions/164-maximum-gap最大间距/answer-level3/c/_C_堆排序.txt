### 解题思路
使用大根堆排序即可解；
排序时，把最大值找出来即可；
![123.PNG](https://pic.leetcode-cn.com/5156d60da97b8cec7414caac9bbf5467342ed1b72e9ec7d6e03aacd7fc096ca8-123.PNG)


### 代码

```c
void Sift(int *data, int low, int high)
{
    int i, j;
    i = low;
    j = 2 * low;
    int tmp = data[i];
    while (j <= high) {
        if (j < high && data[j] <= data[j + 1]) {
            j++;
        }
        if (tmp <= data[j]) {
            data[i] = data[j];
            i = j;
            j = 2 * i;
        } else {
            break;
        }
    }
    data[i] = tmp;
}

int HeapSort(int *data, int n)
{
    for (int i = n / 2; i >= 1; i--) {
        Sift(data, i, n);
    }
    
    int tmp, maxRes, tmpMax;
    maxRes = 0;
    for (int i = n; i >= 1; i--) {
        tmp = data[i];
        data[i] = data[1];
        data[1] = tmp;
        if (i != n) {
            tmpMax = data[i + 1] - data[i];
            if (tmpMax >= maxRes) {
                maxRes = tmpMax;
            }
        }
        Sift(data, 1, i - 1);
    }
    return maxRes;
}

int maximumGap(int* nums, int numsSize) {
    if (nums == NULL) {
        return 0;
    }
    int *data = NULL;
    data = (int *)malloc(sizeof(int) * (numsSize + 1));
    memcpy(&data[1], nums, sizeof(int) * numsSize);
    int maxRes = HeapSort(data, numsSize);
    return maxRes;
}
```