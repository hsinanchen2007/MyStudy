没错，C就是这么简单，就是这么任性。

```c

#if 0
不用自定义类型，直接typedef 为int
typedef struct {
    
} NumArray;
#endif

typedef int NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    return nums;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    int sum = 0;
    for (int n = i; n <= j; n++) {
        sum += obj[n];
    }
    return sum;
}

void numArrayFree(NumArray* obj) {
    return;
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/
```


![image.png](https://pic.leetcode-cn.com/597948c3fe848d79f77d6f1723be305e3f43b72a7de95cd6e126a60b4ed3c044-image.png)

还可以这样：
```c
typedef int NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    for (int i = 1; i < numsSize; i++) {
        nums[i] += nums[i - 1];
    }
    return nums;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    if (i == 0) return obj[j];
    
    return obj[j] - obj[i - 1];
}

void numArrayFree(NumArray* obj) {
    return;
}
```
![image.png](https://pic.leetcode-cn.com/12278e0afed9661b4f74f960be2b29c4890cdddd9cb47f907349c33c552eba07-image.png)

其实哪个更省时间不好评价，主要看用例怎么设计了，第一个适合长数组少调用，第二个适合短数组多调用。