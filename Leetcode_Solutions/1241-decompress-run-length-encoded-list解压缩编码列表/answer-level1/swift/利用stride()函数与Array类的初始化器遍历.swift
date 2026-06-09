执行用时 :72 ms, 在所有 Swift 提交中击败了71.43%的用户
内存消耗 :21.2 MB, 在所有 Swift 提交中击败了100.00%的用户

### 代码

```swift
class Solution {
    func decompressRLElist(_ nums: [Int]) -> [Int] {
        
        //初始化一个用于返回的空数组
        var ans = [Int]()
        
        //利用stride()函数(注意第二个形参标签是"to:"而不是"through:")创建一个能“两两选择”遍历原数组的循环
        for index in stride(from: 0, to: nums.count, by: 2) {
            
            //按照题目要求利用Array类的初始化器“解压”指定的元素到一个临时数组
            var temp = Array(repeating: nums[index + 1], count: nums[index])
            ans += temp
        }
        
        return ans
    }
}

```