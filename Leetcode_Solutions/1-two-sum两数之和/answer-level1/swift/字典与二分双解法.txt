### 解题思路
字典 与 二分两种解法
思路很简单，可以参考代码
### 代码

```swift
//字典解法
class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var result = Array<Int>()
        var dict = Dictionary<Int, Int>()
        for (index, number) in nums.enumerated() {
            if dict.keys.contains(target - number) {
                result.append(dict[target - number]!)
                result.append(index)
            }
            dict[number] = index
        }
        return result
    }
}
```

```swift
//二分解法
class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var newNums = nums.sorted()

        var left = 0
        var right = nums.count - 1
        while left <= right {
            if newNums[left] + newNums[right] == target {
                return [nums.firstIndex(of: newNums[left])!, nums.lastIndex(of: newNums[right])!]
            }else if newNums[left] + newNums[right] > target {
                right -= 1
            }else if newNums[left] + newNums[right] < target {
                left += 1
            }
        }
        return []
    }
}
```