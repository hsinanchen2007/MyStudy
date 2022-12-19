双指针查找交换
```
class Solution {
    func sortArrayByParity(_ A: [Int]) -> [Int] {
        var result = A
        var left = 0
        var right = A.count - 1
        while left != right {
            if result[left]%2 != 0 && result[right]%2 == 0 {
                result.swapAt(left, right)
            }else if result[left]%2 == 0 {
                left += 1
            }else if result[right]%2 == 1 {
                right -= 1
            }
        }
        return result
    }
}
```