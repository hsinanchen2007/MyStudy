### 解题思路
如果还剩一个人，那么这个人的位置肯定是0 。 然后逆向思维，推出还剩两个人的时候，这个人的位置......
人数为1： 0
人数为2： (0+m) % 2
人数为3： ((0+m) % 2 + m) % 3
人数为4： (((0+m) % 2 + m) % 3 + m) % 4


如果用dp的方式来思考本题。
状态：还剩i个人的时候，安全人所在的位置编号 reuslt
状态方程： i ->  i + 1    result = （m + result） % i
初始状态：只剩下安全人 那么位置肯定是 result = 0
### 代码

```swift
class Solution {
func lastRemaining(_ n: Int, _ m: Int) -> Int {
    var result = 0
    for i in 2 ... n {
        result = (m + result) % i
    }
    return result
}
}
```