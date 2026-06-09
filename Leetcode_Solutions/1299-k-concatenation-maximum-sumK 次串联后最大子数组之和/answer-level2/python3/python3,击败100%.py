### 解题思路
首先不必繁琐的从头到尾计算整个数组，在前两个周期内就能解决问题，k>2的时候乘上前面的结果就好了
计算前两个周期的累计最大值，保存一个临时变量，这个变量是前面的累加和，如果前面的累加和大于零，即使当前的数值是小于
0的，但加上累加和之后如果结果仍然大于零，更新累加和，继续遍历 为什么？因为前面的累加和大于零，对后面的结果有正贡献
如果累加和小于零，那么累加和置零。相当于从现在开始重新计算，因为前面一个负的变量，加上后面的任何数字只会使结果更小。

如果k<=2,直接返回结果就行了
如果k>2，(max(sum(arr),0)*(k-2)+res)%mod，这么写的原因是，当sum（arr）<=0 的时候，最终的结果仍然可能是正的，
而（k-2）即多出来的周期，都被0代替。如果 sum(arr)>0， 那么最大的结果是 (k-2)*sum(arr) + 两个周期内的最大值
```
class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        mod=10**9+7
        n=len(arr)
        preSum=res=0
        for i in arr*min(2,k):
            preSum+=i
            if preSum<=0:
                preSum=0
            elif res<preSum:
                res=preSum
        if k>=3:
            return (max(sum(arr),0)*(k-2)+res)%mod
        return res%mod
      
```

            
            


```