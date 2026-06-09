状态：dp[i][j]为s的从头开始到i的子字符串是否为t从头开始到j的子字符串的子序列

状态转移公式：

当char[i]==char[j]时，则字符i一定是j的子序列，如果0~i-1子字符串是0~j-1子字符串的子序列，则dp[i][j]=true，所以dp[i][j] = dp[i-1][j-1]；
当char[i]!=char[i]时，即判断当前0~i子字符串是否是0~j-1的子字符串的子序列，即dp[i][j] = dp[i][j - 1]。如ab，eabc，虽然s的最后一个字符和t中最后一个字符不相等，但是因为ab是eab的子序列，所以ab也是eabc的子序列
初始化：空字符串一定是t的子字符串的子序列，所以dp[0][j]=true
```
func isSubsequence(_ s: String, _ t: String) -> Bool {
    guard s.count >= 0, t.count >= 0 else {return false}
    if s.count == 0 {return true}
    if s.count > t.count {return false}
    var dp = [[Bool]]()
    let sArr = Array(s)
    let tArr = Array(t)
    //初始化
    var verArr = [Bool]()
    for _ in 0..<tArr.count {
        verArr.append(true)
    }
    dp.append(verArr)
    for _ in 1..<sArr.count {
        var initArr = [Bool]()
        for j in 0..<t.count {
            if j == 0 {
                initArr.append(false)
            }
        }
        dp.append(initArr)
    }
    print(dp)
    //dp
    for i in 1..<sArr.count{
        for j in 1..<tArr.count{
            if sArr[i - 1] == tArr[j - 1] {
                dp[i].append(dp[i - 1][j - 1])
            } else {
                dp[i].append(dp[i][j - 1])
            }
        }
    }
    return dp[sArr.count - 1][tArr.count - 1]
}
```
