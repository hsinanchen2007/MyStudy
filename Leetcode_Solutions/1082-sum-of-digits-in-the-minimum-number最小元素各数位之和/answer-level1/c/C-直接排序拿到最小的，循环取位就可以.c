### 解题思路
此题可以排序拿到最小的，然后直接按位取。

核心代码：
```
    while (x != 0) {
        sum += x % 10;
        x /= 10;
    }
```
### 代码

```c
int Compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int sumOfDigits(int* A, int ASize){
    if (A == NULL || ASize == 0) {
        return 1;
    }
    
    qsort(A, ASize, sizeof(int), Compare);
    int x = A[0];
    int sum = 0;
    while (x != 0) {
        sum += x % 10;
        x /= 10;
    }

    if (sum % 2 != 0) {
        return 0;
    }

    return 1;
}
```