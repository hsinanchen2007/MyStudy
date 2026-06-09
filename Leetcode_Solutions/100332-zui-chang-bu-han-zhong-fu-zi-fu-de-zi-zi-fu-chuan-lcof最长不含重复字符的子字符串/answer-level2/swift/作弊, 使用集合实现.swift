### 解题思路
要把字符串转成数组在直接索引访问, 否则直接用String的index访问的话, 会超时...

### 代码

```swift
class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        // 用滑动的窗口, 窗口里面都是不重复的子串, 最后窗口最大长度, 就是无重复子串的长度
        var set = Set<Character>()
        
        // 用left和right来记录当前子串的区间
        var ret = 0
        var left = 0
        let sArr = Array(s)
        
        for right in 0 ..< s.count {
            while set.contains(sArr[right]) {
                // 窗口左边缩小一格
                set.remove(sArr[left])
                left = left + 1
            }
            set.insert(sArr[right])
            if set.count > ret {
                ret = set.count
            }
        }
        return ret
    }
}
```