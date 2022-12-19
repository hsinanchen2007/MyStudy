class Solution {
    func reverseString(_ s: inout [Character]) {
        var start = 0
        var end = s.count - 1
        
        while start < end {
            s.swapAt(start, end)
            start += 1
            end -= 1
        }
    }
}

<!-- 交换指针 -->