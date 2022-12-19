 
这个题目其实和 [打家劫舍||](https://leetcode-cn.com/problems/house-robber-ii/)有一点相似,都是环形的,但是主要的dp的解题思想是不一样的。
打家劫舍的dp(n)表示的是抢第n家最大的收益,即最后的**结果是在最后**。但是这个题目的最大的解不是在最后。这个题目的dp的思想是**选中某一个块披萨**能够**分到**的披萨的**最大值**。 即最大的值其实是在dp的某一个位置上。关键点是**选中某一块披萨能够得到的最大值**

我们用dp[i][j] 表示**选第j块**披萨+在[0,j-2]区间选i块披萨的最大值。选中披萨的数量其实是i+1
dp[0][j] 表示选中第j块+在[0,j-2]区间选0块的披萨的最大值
eg:dg[1][7]  表示选中下标为7的披萨+([0,5]区间选中一块披萨的最大值)。
eg:dg[2][7]  表示选中下标为7的披萨+（[0,5]区间选2块披萨的最大值)----> 在[0,5]区间选2块披萨的最大值其实就是(max(dp[1][0]...dp[1][5])),这个dp[2]就dp[1]关联起来了




```
class Solution {
        func maxSizeSlices(_ slices: [Int]) -> Int {
            
            return max( slicesII(Array(slices[0...slices.count-2])) , slicesII(Array(slices[1...slices.count-1])))
        }
        
        func slicesII(_ slices: [Int]) -> Int {
            let n = slices.count/3 + 1
            var dp: [[Int]] = [[Int]] (repeating: ([Int] (repeating: 0, count: slices.count)), count: n)
            //表示选中第j块的最大值,其实就是原数组
            dp[0] = slices;
            for i in 1..<n {
                var maxVal = 0
                for j in 0..<slices.count {
                    if (j < 2) {
                        dp[i][j] = slices[j]
                    }else{
                        maxVal = max(dp[i-1][j-2], maxVal)   //这个用来存上一行的最大值
                        dp[i][j] = maxVal + slices[j]
                    }
                }
            }
            var res = 0
            for val in dp[n-1] {
                res = max(res, val)
            }
            return res
        }
    }
```
