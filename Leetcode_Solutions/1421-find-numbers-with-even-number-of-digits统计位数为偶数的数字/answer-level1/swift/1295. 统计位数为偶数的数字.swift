### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
    func findNumbers(_ nums: [Int]) -> Int {
        
        let filterNums = nums.filter {
            let str = String($0)
            return str.count % 2 == 0
        }
        return filterNums.count
    }
}
```

利用Swift的高级函数（filter）过滤掉不满足位数为偶数的数。


是元素的位数偶数，而不是元素是偶数！！！