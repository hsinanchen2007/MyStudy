### 解题思路
刚开始也想到了类似滑动窗口，但是用的暴力破解，超时了。
先求数组和，只需要计算n次，然后求k个数的和，就是两个数组和做差了。
注意边界值的判断

### 代码

```c
double findMaxAverage(int* nums, int numsSize, int k){
    //先计算sums数组
    double maxAve = -10000;
    double tmpAve = 0;
    int* sums = (int*)malloc(sizeof(int) * numsSize);
    memset(sums, 0, sizeof(int) * numsSize);
    if (numsSize == 1) {
        return *nums;
    }
    *sums = *nums;
    for(int i = 1;i < numsSize; i++) {
        *(sums + i) =  *(sums + i -1) + *(nums + i);
    }
    if (k == numsSize) {
        maxAve = (double)(*(sums + numsSize - 1))/k;
    }
    for (int j = 0; j <= numsSize - k; j++) {
        if (j == 0) {
            tmpAve = (double)(*(sums + k - 1))/k;
        } else {
            tmpAve = (double)(*(sums + j + k - 1) - *(sums + j -1))/k;
        }
        if (maxAve < tmpAve) {
            maxAve = tmpAve;
        }
        
    }
    free(sums);
    return maxAve;
}
```