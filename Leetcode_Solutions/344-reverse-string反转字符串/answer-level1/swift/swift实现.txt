双指针交换
```
class Solution {
    func reverseString(_ s: inout [Character]) {
        var l = 0
        var r = s.count-1
        while l<r {
            s.swapAt(l, r)
            l += 1
            r -= 1
        }
    }
}
```