### 解题思路
这道题没啥难点，就是考虑两点
1、如何保证循环，取余运算可以解决
2、对最后一个小朋友分糖果注意一下就行
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    *returnSize=num_people;
    int *nums=(int *)malloc(sizeof(int)*num_people);
    memset(nums,0,sizeof(int)*num_people);
    int index=-1;

    int i=1;
    while(candies-i>=0)
    {
        ++index;
        index%=num_people;
        nums[index]=i+nums[index];
        candies-=i;
        i++;
    }
    ++index;
    index%=num_people;
    nums[index]=candies+nums[index];
    return nums;
}
```