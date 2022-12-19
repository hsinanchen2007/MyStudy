### 解题思路
![image.png](https://pic.leetcode-cn.com/7226ecc0d9d9cad195e242c5aa894cc43fec3e99271c33307cebbac4ee1aac28-image.png)
先排序，再遍历，最后加一个条件满足最大值和最小值之间的差别正好是1。

### 代码

```c
int comp(const void* a,const void* b)
{
    return *(int*)a - *(int*)b;    
}

int findLHS(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), comp);
    int max = 0;
    int temp;
    int i, j;
    for(i = 0; i < numsSize; i++) {
        for(j = i + 1; j < numsSize; j++) {
            if(nums[j] - nums[i] < 2) {
                continue;
            } else {
                break;
            }
        }
        if(nums[j - 1] - nums[i]) {
            max = fmax(max, j - i);
        }
    }
    return max;
}
```