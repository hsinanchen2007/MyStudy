### 解题思路
将其中一个数右移，直到1为止。那么每次的解法都等于

 （A右移前的数 - A右移后的数）\* B + A右移后的数 \* B

如实代码就迎刃而解。

其次这里存在重复计算问题，所以使用缓存提高速度。



### 代码

```swift
class Solution {
    var cache = [Int: Int]()
    func multiply(_ A: Int, _ B: Int) -> Int {
        if A == 1 { return B }

        if let D = cache[A] {
            return D
        }

        let C = A >> 1
        let result = multiply(A - C, B) + multiply(C, B)

        cache[A] = result
        return result
    }
}
```