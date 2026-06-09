### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
func maxDepthAfterSplit(_ seq: String) -> [Int] {
    var depth = 0
    var result:[Int] = [Int]()
    for item in seq {
        if item == "(" {
            depth += 1
            result.append(depth % 2)
        } else {
            result.append(depth % 2)
            depth -= 1
        }
    }
    return result
}

}
```