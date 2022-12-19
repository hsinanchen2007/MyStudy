### 解题思路
利用Set是无序无重复数据的集和，去掉String中重复的元素。与原字符串长度对比。

### 代码

```swift
class Solution {
    func isUnique(_ astr: String) -> Bool {
        return Set<Character>(astr).count == astr.count
    }
}
```
