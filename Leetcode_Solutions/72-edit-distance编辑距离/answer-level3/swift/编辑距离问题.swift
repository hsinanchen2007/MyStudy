### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
func minDistance(_ word1: String, _ word2: String) -> Int {
    let word1Array = word1.map{$0}
    let word2Array = word2.map{$0}
    
    let length1 = word1Array.count
    let length2 = word2Array.count
    
    if length1 * length2 == 0 {
        return length2 + length1
    }
    
    //dp[m][n]
    var dp = Array(repeating: Array(repeating: 0, count: length2 + 1), count: length1 + 1)
    for i in 0 ... length1 {
        dp[i][0] = i
    }
    for j in 0 ... length2 {
        dp[0][j] = j
    }
    

    
    for i in 1 ... length1 {
        for j in 1 ... length2 {
            if word1Array[i - 1] == word2Array[j - 1] {
                dp[i][j] = dp[i - 1][j - 1]
            } else {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j] , dp[i - 1][j - 1]) + 1
            }
        }
    }
    
    return dp[length1][length2]
}


}
```