### 解题思路
该题的思路为：由于需要找到重复数字，所以创建一个集合，然后对数组进行遍历，如果集合中存在数字，则直接返回数字

### 代码

```swift
class Solution {
    func findRepeatNumber(_ nums: [Int]) -> Int {
        // 创建集合
        var set = Set<Int>()
        
        // 对数组进行遍历,因为只需要用其中的数字,所以前面的序号index设置为_
        for (_, num) in nums.enumerated() {
            if set.contains(num) {
                return num
            } else {
                set.insert(num)
            }
        }
        
        // 如果没有就返回-1
        return -1
    }
}

```