### 解题思路
根据1的位数进行排序，如果位数相同则根据大小进行排序。countBits函数可以用来计算每个数的1的位数。cmp函数根据1的位数对两个数进行判断，当两个数的1的位数相同时，则根据两个数的大小进行判断是否需要在排序中交换位置，当两个数的1的位数不同时，根据位数的大小判断是否需要在排序中交换位置。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countBits(int n) {
    int count = 0;
    if(n == 0) return 1;
    while (n) {
        if (n % 2) count++;
        n /= 2;
    }
    return count;
}

bool cmp(int a, int b) {
    int ba = countBits(a);
    int bb = countBits(b);
    if (ba == bb) return a < b;
    else return ba < bb;
}

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int* sortByBits(int* arr, int arrSize, int* returnSize){
    *returnSize = arrSize;
    for (int i = 0; i < arrSize - 1; ++i) {
        for (int j = i + 1; j < arrSize; ++j) {
            if (!cmp(arr[i], arr[j])) {
                swap(arr, i, j);
            }
        }
    }
    return arr;
}
```