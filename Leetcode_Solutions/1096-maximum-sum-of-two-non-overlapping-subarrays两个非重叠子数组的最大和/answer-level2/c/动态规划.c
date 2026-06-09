### 解题思路
1、LMax[i] 用于保存0到i之间L长度的子数组最大和。
2、LRMax[i] 用于保存ASize - 1反向到i之间L长度的子数组最大和。
3、遍历数据计算每个M长度的子数组的和，在每个M长度的子数组的左右两边找到L长度的子数据的最大和，相加最大的就是最终的答案。

### 代码

```c
#define MAX(A, B) ((A) > (B) ? (A) : (B))
int* MaxSumArr(int* A, int ASize, int subLength) 
{
    int* arr = malloc(sizeof(int) * ASize);
    memset(arr, 0, subLength);

    int sum = 0;
    for (int i = 0; i < subLength; i++) {
        sum += A[i];
    }
    arr[subLength - 1] = sum;
    int maxSum = sum;
    for (int i = subLength; i < ASize; i++) {
        sum += A[i] - A[i - subLength];
        if (sum > maxSum) {
            maxSum = sum;
        }
        arr[i] = maxSum;
    }
    return arr;
}

int* MaxSumArrReverse(int* A, int ASize, int subLength) 
{
    int* arr = malloc(sizeof(int) * ASize);
    memset(arr, 0, ASize);
    int sum = 0;
    for (int i = ASize - 1; i >= ASize - subLength; i--) {
        sum += A[i];
    }
    arr[ASize - subLength] = sum;
    int maxSum = sum;
    for (int i = ASize - subLength - 1; i >= 0; i--) {
        sum += A[i] - A[i + subLength];
        if (sum > maxSum) {
            maxSum = sum;
        }
        arr[i] = maxSum;
    }
    return arr;
}

int maxSumTwoNoOverlap(int* A, int ASize, int L, int M)
{
    /* LMax[i]代表从0到i的L长度的最大和 */
    int *LMax = MaxSumArr(A, ASize, L);
    int *LRMax = MaxSumArrReverse(A, ASize, L);
    int sum = 0;
    for (int i = 0; i < M; i++) {
        sum += A[i];
    }
    int maxSum = sum + LRMax[M];
    for (int i = M; i < ASize; i++) {
        sum += A[i] - A[i-M];
        if (i < ASize - 1) {
            maxSum = MAX(maxSum, sum + MAX(LMax[i-M], LRMax[i+1]));
        } else {
            maxSum = MAX(maxSum, sum + LMax[i-M]);
        }
    }
    return maxSum;
}
```