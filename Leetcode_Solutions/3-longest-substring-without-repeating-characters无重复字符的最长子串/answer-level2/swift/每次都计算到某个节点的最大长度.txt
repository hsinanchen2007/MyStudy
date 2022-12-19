### 解题思路
我其实是复制了高赞答案的想法，这里记录一下思路。
- 首先两层循环是不可避免的，用来遍历字符串开头和结尾的下标。
- 从第一层循环内部来看，实质上是每次找出以当前节点为终点的满足条件的最大长度
- 如果在内部循环时发现某节点和当前外层节点字符一样，那么意味着下次可以以这个节点后一个为起点。这一点需要考虑清楚。

算法还是要多多揣摩。

### 代码

```swift
class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        // 开始先将化为数组
        var characters: [Character] = []
        for a in s {
            characters.append(a)
        }
        
        let length = s.count
        var start = 0 //用于每次循环的起点
        var maxLength = 0
        for index in 0..<length {
            for internalIndex in start..<index {
                if characters[index] == characters[internalIndex] {
                    start = internalIndex + 1
                    break
                }
            }
            if index-start+1 > maxLength {
                maxLength = index-start+1
            }
        }
        return maxLength
    }
}
```