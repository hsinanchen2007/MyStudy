最近写的一遍两数之和问题让我意外的是内存消耗优于100%的提交，不过耗时大众型
虽然放在现在来讲快才是第一要意，我还是想来在这里写下我的想法

也很简单，两数之和，用targe减去其中一个数得到另一个数mod，再在数组中寻找有没有这个数
两次遍历，代码如下，只要找到那么就会保存退出循环

```c
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i;
    int j;
    int mod;
    int* a = NULL;
    *returnSize = 2;
    a = (int*)malloc(*returnSize * sizeof(int));

    for (i = 0; i < numsSize; ++i) {
        mod = target - nums[i];
        for (j = 0; j < numsSize; ++j) {
            if (i == j) continue;
            if (mod == nums[j]) break;
        }
        if (j == numsSize) 
            continue;
        else{
            a[0] = i;
            a[1] = j;
            break;
        }
    }

    return a;
}
```
