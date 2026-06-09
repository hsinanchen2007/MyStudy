### 解题思路
执行用时 :16 ms, 在所有 Swift 提交中击败了83.10%的用户
内存消耗 :20.4 MB, 在所有 Swift 提交中击败了83.67%的用户

![截屏2020-02-14上午2.49.41.png](https://pic.leetcode-cn.com/125121b106f65c9874a85457b14755ee9c6100bc5799db51a99b0f38ee5de7de-%E6%88%AA%E5%B1%8F2020-02-14%E4%B8%8A%E5%8D%882.49.41.png)

比较旋转前与旋转后，二维数组的下标得出规律`new90[i][j] = old[n-j-1][i]`

### 代码

```swift
class Solution {
    func rotate(_ matrix: inout [[Int]]) {
        let n = matrix.count
        if n <= 1 {
            return
        }
        let mat = matrix
        for i in 0..<n {
            for j in 0..<n {
                matrix[i][j] = mat[n-j-1][i]
            }
        }
    }
}
```