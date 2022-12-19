### 解题思路
思路就是用一个字典/哈希表来进行数字的存储

### 代码

```swift
class Solution {
    func singleNumber(_ nums: [Int]) -> Int {
        // 1. 建立一个[Int:Int]字典，
        var dict: [Int:Int] = [:]

        // 2. 对数组进行遍历，有一个数就增加一个计数
        for num in nums {
            dict[num, default: 0] += 1
        }

        // 3. 最后遍历字典，返回找出计数为1的
        for e in dict{
            if e.value == 1 {
                return e.key
            }
        }

        return -1

    }
}
```