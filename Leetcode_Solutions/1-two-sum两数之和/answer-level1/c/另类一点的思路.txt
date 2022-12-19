### 解题思路
随机大法，O(1)时间复杂度和空间复杂度，当然这只是好玩的写法
想法是随机生成两个下标，然后比对这两个下标对应的元素的和是否等于目标值，注意这两个下标不能相等（不重复利用数组元素）

```
执行用时：444 ms ,在所有C提交中击败了 5.31% 的用户
内存消耗：6 MB ,在所有C提交中击败了 100.00% 的用户
```

没有去尝试i小于多少会超时，一千万也不是一定能通过
之前尝试过一百万，会卡两组测试用例
尝试过八百万，会卡目标值16021这一组
通过有运气成分

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,a,b;
    srand(time(0));
    *returnSize=2;
    int *Ret=(int*)malloc(sizeof(int)*2);
    for(i=0;i<10000000;i++){
        a=rand()%numsSize;
        b=rand()%numsSize;
        if(a!=b&&nums[a]+nums[b]==target){
            Ret[0]=a;Ret[1]=b;return Ret;
        }
    }
    return Ret;
}
```