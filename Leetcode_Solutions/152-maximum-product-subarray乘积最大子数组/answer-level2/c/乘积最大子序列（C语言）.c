### 解题思路
当有两个数A和B,(A > B), 
       - 如果A和B同时乘C(C>0), 那么 A×C > B×C
       - 如果A和B同时乘C(C<0), 那么 A×C < B×C
所以要如果要计算乘积最大的连续子序列，要保存当前乘积的，最大值和最小值 （因为如果下一个乘数是负数的话，最小值*负数>最大值*负数，可以举一些例子）
因此思路如下
        - 定义两个数组，分别保存计算到当前的数组的连续最大数和最小数。
最后的结果就是连续最大整数中的最大值。
### 代码

```c

int maxProduct(int* nums, int numsSize){
    // 申请空间
    int *maxEr = (int *)calloc(sizeof(int), numsSize);
    int *minEr = (int *)calloc(sizeof(int), numsSize);
    int result = nums[0];
    maxEr[0] = minEr[0] = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > 0) {
            maxEr[i] = max(maxEr[i-1]*nums[i], nums[i]);
            minEr[i] = min(minEr[i-1]*nums[i], nums[i]);
        } else if (nums[i] < 0){
            maxEr[i] = max(minEr[i-1]*nums[i], nums[i]);
            minEr[i] = min(maxEr[i-1]*nums[i], nums[i]);
        } else {
            maxEr[i] = 0;
            minEr[i] = 0;
        }
    }
    for (int i = 1; i < numsSize; i++) {
        result = maxEr[i] > result ? maxEr[i] : result;
    }

    // 释放空间
    free(maxEr);
    free(minEr);

    return result;
}

int min(int x, int y) {
    return x > y ? y : x;
}

int max(int x, int y) {
    return x > y ? x : y;
}
```