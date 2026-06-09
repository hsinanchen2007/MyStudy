### 解题思路

用一个right和left计数指针，用了swift的新方法swapAt，提替换了两个值交换的方法

### 代码

```swift
class Solution {
    func reverseString(_ s: inout [Character]) {
        guard !s.isEmpty else {
            return
        }
        var right = s.count-1;
        var left = 0;
        while (left < right) {

            s.swapAt(left, right);
            left += 1;
            right -= 1;
        }
    }
}
```