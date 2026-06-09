### 解题思路
首尾两两交换位置，注意边界条件，什么时候停止交换
使用i、j两个指针，一前一后去交换元素

### 代码

```swift
class Solution {
    func reverseString(_ s: inout [Character]) {
            var i = 0
            var j = s.count-1
            while i < j {
                s.swapAt(i, j)
                i += 1
                j -= 1
            }
    }
}
```