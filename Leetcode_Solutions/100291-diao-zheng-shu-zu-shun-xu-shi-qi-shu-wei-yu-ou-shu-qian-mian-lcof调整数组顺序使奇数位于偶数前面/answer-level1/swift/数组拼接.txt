### 数组拼接
### 代码

```swift
class Solution {
    func exchange(_ nums: [Int]) -> [Int] {
        var array1 = [Int]()
        var array2 = [Int]()
        for num in nums {
            if num % 2 != 0 {
                array1.append(num)
            } else {
                array2.append(num)
            }
        }
        return array1 + array2
    }
}
```