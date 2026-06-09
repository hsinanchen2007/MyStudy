### 思路

走到一个格子的步数 = 走到这个格子上面的格子的步数 + 走到这个格子左边的步数

### 题解

本来用递归是可以实现的，但到了 `13,19` 这个测试用例就会超出时间限制

一下子想到了 leetcode 斐波那契**三步走**：
[动态规划套路详解 - 斐波那契数 - 力扣（LeetCode）](https://leetcode-cn.com/problems/fibonacci-number/solution/dong-tai-gui-hua-tao-lu-xiang-jie-by-labuladong/)

```text
f(x, y) = f(x-1, y) + f(x, y-1) (x>1, y>1)
f(x, y) = 1 (x = 1 或 y = 1)
f(x, y) = f (y, x)
```
### 代码
``` Swift
class Solution {
  func uniquePaths(_ m: Int, _ n: Int) -> Int {
    // 这里有一个小技巧，一个字典也是 `AnyHashable` 的
    var store : [[Int:Int]:Int] = [[0:1]:1, [1:0]:1]
    for i in 1...m {
      for j in 1...n {
        if i <= 1 || j <= 1 {
          store[[i:j]] = 1
        } else {
          store[[i:j]] = store[[j:i]] ?? (store[[i-1:j]]! + store[[i:j-1]]!)
        }
      }
    }
    return store[[m:n]]!
  }
}
```

空间复杂度和时间复杂度都是 `O(m * n)`
