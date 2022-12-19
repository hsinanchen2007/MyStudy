# 参考热评01背包解法，通过golang实现

```
//动态规划(0-1背包问题)
func findTargetSumWays(nums []int, S int) int {
    if len(nums)==0 || nums==nil{
        return 0
    }
    sum:=0
    for i:=0;i<len(nums);i++{
        sum+=nums[i]
    }
    //如果sum<S,说明不能实现该目标和
    if sum < S{
        return 0
    }
    //否则将S加入sum
    sum+=S
    if sum%2!=0{
        return 0
    }
    //定义状态
    dp:=make([]int,sum/2+1)
    dp[0]=1
    for i:=0;i<len(nums);i++{
        for j:=sum/2;j>=nums[i];j--{
            dp[j]=dp[j]+dp[j-nums[i]]
        }
    }
    return dp[sum/2]
}
```
## 01背包的实现原理详见热评，写的时候只需要注意给的案例有时S会很大，nums的和小于S，直接返回0即可
## 剩下的直接套用01背包的模板就行
