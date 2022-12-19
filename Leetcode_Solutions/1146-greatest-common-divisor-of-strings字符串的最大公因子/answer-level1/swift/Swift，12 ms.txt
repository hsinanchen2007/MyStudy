根据 [wonderful611 的题解](https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/solution/1071-zi-fu-chuan-de-zui-da-gong-yin-zi-by-wonderfu/) 出的 Swift 版，大佬思路果然清晰，膜。自己大概又再理了一下思路：

1. 首先充要条件为 `str1 + str2 != str2 + str1`，不满足直接返回空串；
2. 根据 `str1.count` 和 `str2.count` 求最大公约数，记作 `greatestDivisor`；
3. 取 `str1` 或 `str2` 中任意一个的前 `greatestDivisor` 位，即为结果。
 
这里第一遍看时没想明白，理论最优长度（最大公约数 `greatestDivisor`）凭什么每次都能达到呢？因为第一步的充要条件已达成，所以必然存在某个公约数使结果成立，我们假设它不是最大公约数，那么就会有一个小于 `greatestDivisor` 的公约数我们记作 `notGreatestDivisor`，那么就有两种情况，情况一：如果 `notGreatestDivisor` 不是 `greatestDivisor` 的约数，又因为 `notGreatestDivisor` 和 `greatestDivisor` 都为 `str1.count` 和 `str2.count` 的公约数，那么必然存在一个更大的公约数 `notGreatestDivisor * greatestDivisor`，但 `greatestDivisor` 已经是最大的了，所以不成立；情况二：如果 `notGreatestDivisor` 是 `greatestDivisor` 的约数，也就是说存在第三个公约数 `anotherDivisor` 使 `notGreatestDivisor * anotherDivisor = greatestDivisor` 成立，此时 `anotherDivisor` 也是 `str1.count` 和 `str2.count` 的公约数，公共子串翻个 `anotherDivisor` 公约数倍肯定还是公共子串，所以公共子串必然可以扩大为 `greatestDivisor`；综上所以最大公因子长度必然为 `greatestDivisor`。
<br>
```swift
class Solution {
    func gcdOfStrings(_ str1: String, _ str2: String) -> String {
        if str1 + str2 != str2 + str1 { return "" }
        let greatestDivisor = greatestCommonDivisor(val1: str1.count, val2: str2.count)
        return String(str1.prefix(greatestDivisor))
    }
    
    func greatestCommonDivisor(val1: Int, val2: Int) -> Int {
        if val1 == val2 {
            return val1
        } else if val1 > val2 {
            return greatestCommonDivisor(val1: val1 - val2, val2: val2)
        }
        return greatestCommonDivisor(val1: val2 - val1, val2: val1)
    }
}
```