### 解题思路
此处撰写解题思路
比较大小得函数，动态规划3步骤
1.定义数组dp的意义
2.找出临界的关系，第n步骤时用n-1时刻的关系式表达出来
3.找到初值


### 代码

```golang

func max(a,b int) int{
    if a>b{
        return a
    }
    return b
}

func rob(nums []int) int {
    if len(nums)==0{
        return 0
    }
    dp:=make([]int,102)
    dp[0]=0
    dp[1]=nums[0]
    for i:=2;i<=len(nums);i++{
        dp[i]=max(dp[i-2]+nums[i-1],dp[i-1])
    }
    return dp[len(nums)]
}
```