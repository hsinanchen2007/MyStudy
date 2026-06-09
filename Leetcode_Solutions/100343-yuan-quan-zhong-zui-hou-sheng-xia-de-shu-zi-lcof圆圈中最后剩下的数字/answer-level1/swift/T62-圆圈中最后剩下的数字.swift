### 解题思路
大概的思路用一个数组来模拟环，然后每次删除m-1个位置的数，如果超界，就进行取余操作。

### 代码

```swift
class Solution {
    func lastRemaining(_ n: Int, _ m: Int) -> Int {
        var nums: [Int] = []
        for index in 0..<n {
            nums.append(index)
        }

        var intm = 0

        while nums.count != 1 {
            intm = (intm + m - 1) % nums.count
            nums.remove(at:intm)
        }

        return nums[0]


    }
}
```