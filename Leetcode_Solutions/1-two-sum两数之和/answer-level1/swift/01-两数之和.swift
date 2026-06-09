### 解题思路
- 直接使用暴力解法
- 根据官方的一次的哈希，因为Swift没有哈希，所以在取之前的数的序列的时候还是需要用到数组。

### 代码

```swift
class Solution {
    func twoSum(_ A: [Int], _ target: Int) -> [Int] {
        // for i in 0..<nums.count {
        //     for j in i+1..<nums.count {
        //         if nums[i] + nums[j] == target {
        //             let arr = [i, j]
        //             return arr
        //         }
        //     }
        //

        var nums = A
        var hashTable = Set<Int>()
        
        for (index, num) in nums.enumerated() {
            let prevNum = target - num
            if hashTable.contains(prevNum) {
                let prevIndex = nums.firstIndex(of:prevNum)!
                return [prevIndex, index]
            }
            hashTable.insert(num)
        }
        
        assert(false, "NO SOLUTION")
    }
}
```