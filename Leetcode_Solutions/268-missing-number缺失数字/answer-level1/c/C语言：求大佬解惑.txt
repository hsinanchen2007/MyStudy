`这道题的官方题解写得很好，建议大家看看`
这道题总给我意料之外的感受
当想出来**快速排序**，觉得应该是比较慢的，我要再想出快一点的

```
int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int missingNumber(int* nums, int numsSize){
    int i;
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    if (nums[0] != 0)
        return 0;
    if (nums[numsSize - 1] != numsSize)
        return numsSize;
    for (i = numsSize - 1; i >= 0; i--){
        if (nums[i] != i + 1)
            break;
    }
    return i + 1;
}
```
于是我又用**哈希**的思想做了，的确快了一点，但是没想到怎么比快排快，我遍历了近两遍数组啊？

```
int missingNumber(int* nums, int numsSize){
    int sign[numsSize + 1], i, j;
    
    memset(sign, -1, (numsSize + 1) * sizeof(int));
    for (i = 0; i < numsSize; i++)
        sign[nums[i]]++;
    for (j = numsSize; j >= 0; j--){
        if (sign[j] == -1)
           break;
    }
    return j;
}
```
后来我左看右看，灵机一动想出来了一遍遍历就知道答案的方法，
**先求前(numsSize + 1)项和，（以0作为开头），然后减去数组中的每一个元素，剩下的差值就是答案。**
心想，这次肯定超越100%了，可是一实践，竟然最慢，32ms.我迷惑了。
```
/*等差数列求和公式求前numsSize + 1项和，
首项0,末项numsSize,项数：numsSize + 1.
*/
int missingNumber(int* nums, int numsSize){
    int sum = numsSize * (numsSize + 1) / 2;

    for (int i = 0; i < numsSize; i++){
        sum -= nums[i];
    }
    return sum;
}
```
后来去提交记录处取经，终于看到了超越100%的方法，把膝盖放在那儿了
**位异或**操作也太骚了吧
```
int missingNumber(int* nums, int numsSize){
    int i,res=numsSize;
    for(i=0;i<numsSize;i++){
        res^=i^nums[i];
    }
    return res;
}
```

# 哪位大佬帮我分析这几种方法的时间效率，感激不尽

