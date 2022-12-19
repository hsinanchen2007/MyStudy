### 解题思路
提交过冒泡排序和插入排序, 都超时了, 题目隐含了时间复杂度的要求, (我的方案里)就剩下
快速排序了.

思路是二分法和分治,每次循环都会把问题域缩小.


执行用时 : 196 ms, 在所有 swift 提交中击败了89.09%的用户
内存消耗 : 23.5 MB, 在所有 swift 提交中击败了100.00%的用户

### 代码

```swift
class Solution {
    func sortArray(_ nums: [Int]) -> [Int] {
        var temp = nums
        quickSort(&temp, left: 0, right: nums.count-1)
        return temp
    }

    func quickSort(_ nums: inout [Int], left: Int, right: Int) {
	
        guard left<=right else {
            return
        }
        
        let pivot = partition(&nums, left: left, right: right)
        quickSort(&nums, left: left, right: pivot-1)
        quickSort(&nums, left: pivot+1, right: right)
    }

    func partition(_ nums: inout [Int],  left: Int, right: Int) -> Int {
        var left = left 
        var right = right
        let pivot = nums[left]
        
        while left<right {
            while left<right, nums[right]>=pivot {
                right -= 1
            }
            nums[left] = nums[right]

            while left<right, nums[left]<pivot {
                left += 1
            }
            nums[right] = nums[left]
        }
        
        nums[left] = pivot
        
        return left
    }
}
```