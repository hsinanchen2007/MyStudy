### 解题思路
双指针, 注意的地方是比较的值, 是否随着指针移动而变更.
第二种解法是看到测试用例输出的值是 Array 而不是数量, 所以修改了数组, 可以直接输出正确的 Array

### 代码

```swift
class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
    
        // 先做错误处理
        if nums.count==0 || nums.count==1 {
            return nums.count
        }
        var index = 0
        for i in 0..<nums.count {
            if nums[i] != nums[index] {
                index += 1
            }
        }
        return index+1
    }


    func removeDuplicates2(_ nums: inout [Int]) -> Int {
        if nums.count==0 || nums.count==1 {
            return nums.count
        }
        var index = 0
        while (index != nums.count-1){
            if nums[index]==nums[index+1] {
                nums.remove(at: index)
            }else {
                index = index + 1
            }
        }
        return nums.count;
    }

    func removeDuplicates3(_ nums: inout [Int]) -> Int {
        if nums.count==0 || nums.count==1 {
            return nums.count
        }
        var index = 0
        var next = 1
        while (next < nums.count){
            if nums[index] == nums[next] {
                next = next + 1
            }else {
                index = index + 1
                nums[index] = nums[next]
                next = next + 1
            }
        }
        return index+1;
    }
}
```