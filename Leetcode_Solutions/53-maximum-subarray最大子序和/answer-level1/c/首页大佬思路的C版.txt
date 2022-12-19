### 解题思路
此处撰写解题思路
首页大佬JVAV代码的C版
### 代码

```c
int maxSubArray(int* nums, int numsSize){
    int sum=0,ans=nums[0],a;
    for (a= 0; a < numsSize; a++)
    {
        if (sum > 0)
            sum+=nums[a];
        else 
        sum = nums[a];
        ans = sum > ans ? sum : ans;
    }
    return ans;
}
、、、