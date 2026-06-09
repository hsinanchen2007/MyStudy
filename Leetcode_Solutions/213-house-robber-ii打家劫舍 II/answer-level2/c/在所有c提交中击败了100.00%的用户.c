### 解题思路
![打家劫舍2.png](https://pic.leetcode-cn.com/70da7300399f059d4ab5fe4c6a4bec7e43e55225313b3e94c7b26df799156c0e-%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8D2.png)

### 代码

```c
int rob(int* nums, int numsSize){
    if(numsSize==0)
        return 0;
    if(numsSize==1)
        return nums[0];   
    if(numsSize==2)
        return  (nums[0]>nums[1])?nums[0]:nums[1];
    int ans1[numsSize];//打劫第一家，不打劫最后一家
    int ans2[numsSize];//不打劫第一家，最后一家可打劫可不打劫
    ans1[0] = nums[0];
    ans1[1] = nums[0];
    ans2[0]=0;
    ans2[1]=nums[1];
    if(numsSize==3)//假设一的边界值
        //如果只有3所房子，在假设打劫第一家，不打劫最后一家时，小偷所得为第1个房子的资金
         {
          ans1[2]=nums[0];
    //ans2[2] = ((nums[2] + ans2[2 - 2])>ans2[2 - 1])?(nums[2] + ans2[2 - 2]):ans2[2 - 1];
       ans2[2]=nums[2]>nums[1]?nums[2]:nums[1];
        return ans1[2]>ans2[2]?ans1[1]:ans2[2];
         } 
    for (int i = 2; i< numsSize-1; i++) 
    { 
        ans1[i] = ((nums[i] + ans1[i - 2])>ans1[i - 1])?(nums[i] + ans1[i - 2]):ans1[i - 1];
        ans2[i] = ((nums[i] + ans2[i - 2])>ans2[i - 1])?(nums[i] + ans2[i - 2]):ans2[i - 1];
    }
    ans2[numsSize-1]=((nums[numsSize-1] + ans2[numsSize-3])>ans2[numsSize-2])?(nums[numsSize-1] + ans2[numsSize-3]):ans2[numsSize-2];
    return ans1[numsSize - 2]>ans2[numsSize-1]?ans1[numsSize - 2]:ans2[numsSize-1];
}
```