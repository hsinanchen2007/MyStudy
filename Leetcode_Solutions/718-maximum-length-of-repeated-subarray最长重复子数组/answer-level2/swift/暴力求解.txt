- 时间复杂度最坏为O(n.m),n是A的长度，m是B的长度；
- 从左到右对A进行遍历
- 针对每一个A，都需要从B的每一个位置开始尝试求出当前的重复子数组
- 利用对于剩余子数组如果小于当前求得的最大长度及时终止剩余遍历
```
class Solution {
    func findLength(_ A: [Int], _ B: [Int]) -> Int {
        var maxLength = 0
        let m = A.count
        let n = B.count
        var i = 0
        while i<m {
            if m-i < maxLength {
                break
            }
            var j = 0
            while j<n {
                if n-j < maxLength {
                    break
                }
                var ii = i
                var jj = j
                var length = 0//求解本次的长度
                while ii<m && jj<n && A[ii] == B[jj] {
                    length += 1
                    ii += 1
                    jj += 1
                }
                maxLength = max(maxLength, length)
                j += 1
            }
            i += 1
        }
     
        return maxLength    
    }
}
```
