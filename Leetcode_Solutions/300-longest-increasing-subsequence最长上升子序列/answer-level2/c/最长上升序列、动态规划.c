### 解题思路
在颓废了好几天之后遇到了这样一道很有收获的题
参考了[最长上升子序列（动态规划 + 二分查找，清晰图解）](https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-dong-tai-gui-hua-2/)的清晰的解释。
这种动态规划的思想是找到**每一个子序列**（即局部）的最长上升序列，最终得到全局的最长上升子序列。当然这是泛泛而谈，因为动态规划真的很“博大精深”。

具体地说，本题最关键的数组dp[]的含义是：
dp[i]指的是序列nums的0到i-1之间最长的上升子序列长度。

代码中`if(nums[i]>nums[j]) dp[i]=maxVal(dp[j]+1,dp[i]);`才是关键，这一点是我想了比较久才想明白的，`maxVal(dp[j]+1,dp[i])`的实际上是一箭双雕：
1.找到dp[0到i-1]之间最大的值；
2.将这个最大值加1赋给dp[i]。

明白了这一点，一下代码也是可以换一种方式的，即直接找到dp[0到i-1]之间的最大值然后赋给dp[i]即可。


### 代码

```c
int maxVal(int i,int j){
    if(i>j) return i;
    else return j;
}

int lengthOfLIS(int* nums, int numsSize){
    if(numsSize==0) return 0;
    int *dp=(int*)malloc(sizeof(int)*numsSize);
    int i,j,ans=0;

    for(i=0;i<numsSize;i++){
        //细节，这样就不用单独初始化dp了
        dp[i]=1;
        for(j=0;j<i;j++){
            if(nums[i]>nums[j]) dp[i]=maxVal(dp[j]+1,dp[i]);
        }
        ans=maxVal(ans,dp[i]);
    }
    return ans;
}
```