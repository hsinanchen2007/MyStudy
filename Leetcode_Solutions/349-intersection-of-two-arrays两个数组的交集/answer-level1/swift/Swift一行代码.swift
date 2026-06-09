### 解题思路
把两个数组转为Set，用swift内置方法取交集再转为Array

### 代码

```swift
class Solution {
    func intersection(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        return Array(Set(nums1).intersection(Set(nums2)))
    }
}
```