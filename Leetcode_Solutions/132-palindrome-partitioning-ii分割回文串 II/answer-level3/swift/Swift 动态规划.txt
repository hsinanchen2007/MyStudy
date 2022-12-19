### 解题思路
划分型dp  
先处理一下字符串 用dpp记录i~j是否为回文串  
接着遍历0~i 用dp[i]表示分割0~i需要的最小次数  
如果ddp[i]为true 也就是说0~i是回文 那么不需要分割 也就是需要0次  
如果ddp[i]为false 也就是代表0~i不是回文 那么我们先默认它为最坏情况 即需要分割i次 也就是每一个字符都需要分割  
然后再遍历0~i这个区间 如果j~i是回文 那么此时可以对比一下0~j-1需要的次数+1（我们把j~i分割一次，所以需要+1）和目前dp[i]的数值取较小的  
那么dp[i] = min(dp[i], dp[j - 1] + 1)  
至此就完工了 注意一下边界条件
### 代码

```swift
class Solution {
    func minCut(_ s: String) -> Int {
        let str = Array(s)
        let len = str.count
        if len <= 1 {
            return 0
        }
        //dpp[i][j] 记录 从i到j 是否为回文
        var dpp = Array(repeating: Array(repeating: false, count: len), count: len)
        let arr = Array(s)
        for i in 0 ..< len {
            dpp[i][i] = true
            if i < len - 1 {
                if arr[i] == arr[i + 1] {
                    dpp[i][i + 1] = true
                }
            }
        }
        for c in 3 ..< len + 1 {
            for i in 0 ..< len - c + 1 {
                let l = i
                let r = i + c - 1
                if arr[l] == arr[r] {
                    dpp[l][r] = dpp[l + 1][r - 1]
                }
            }
        }
        var dp = Array(repeating: len, count: len + 1)
        for i in 0 ..< len {
            if dpp[0][i] {
                //0~i是回文 那么不需要划分 比如 aab 当i为0或者1的时候
                dp[i] = 0
            } else {
                //0~i不是回文 那么z先默认要分割i次 比如 aab默认分割2次即 a a b 三个都是回文 默认为最差情况
                dp[i] = i
                //遍历从1~i
                for j in stride(from: 1, through: i, by: 1) {
                    //如果从j到i是回文 尝试分割一次
                    if dpp[j][i] {
                        dp[i] = min(dp[i], dp[j - 1] + 1)
                    }
                }
            }
        }
        return dp[len - 1]
    }
}
```