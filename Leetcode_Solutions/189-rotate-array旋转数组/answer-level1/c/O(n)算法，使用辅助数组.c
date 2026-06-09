### 解题思路
如下代码

### 代码

```c
// V1 笨办法，使用一个辅助数组
void rotate(int* nums, int numsSize, int k){
    k = k % numsSize;   // 注意mod

    int tmp[numsSize];
    int i;

    // 将后面k个元素的复制到tmp的前k个位置
    for ( i=0; i< k; i++ ) {        
        tmp[k-i-1] = nums[numsSize-i-1];
        // printf("%d\n", nums[numsSize-i-1]);
    }
    // 将剩下的复制过去
    for ( i=0; i<numsSize-k; i++ ) {
        tmp[k+i] = nums[i];
    }
    // 用tmp来覆盖原来数组
    for ( i = 0; i < numsSize; i++ ) {
        nums[i] = tmp[i];
    }
}
```