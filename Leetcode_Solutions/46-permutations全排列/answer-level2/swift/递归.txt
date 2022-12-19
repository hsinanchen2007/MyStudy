### 解题思路
逐级递归把数组分解，然后再合并

### 代码

```swift
class Solution {
func permute(_ nums: [Int]) -> [[Int]] {
    guard nums.count > 1 else { return [nums] }
    var tmpNums = nums
    let l = tmpNums.removeLast()
    let array = permute(tmpNums)
    return array.reduce(into: [[Int]]()) { (result, element) in
        for i in element.startIndex...element.endIndex {
            var tmpElement = element
            tmpElement.insert(l, at: i)
            result.append(tmpElement)
        }
    }
}
}
```