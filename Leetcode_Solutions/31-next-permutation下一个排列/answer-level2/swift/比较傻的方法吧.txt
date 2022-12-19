### 解题思路
此处撰写解题思路

### 代码

```swift
class Solution {
func nextPermutation(_ nums: inout [Int]) {
    guard nums.count > 1 else { return }
    
//冒泡排序
    func bubbleSort(nums: inout [Int], range: ClosedRange<Int>) {
        guard range.count > 1 else { return }
        for i in (range.lowerBound + 1)...range.upperBound {
            for j in (i...range.upperBound).reversed() {
                let k = j - 1
                if nums[k] > nums[j]  {
                    (nums[k], nums[j]) = (nums[j], nums[k])
                }
            }
        }

    }
    
    var max: Int!
    for i in (0..<nums.endIndex).reversed() {
        if max == nil {
            max = nums[i]
        } else {
            if max < nums[i] {
                max = nums[i]
            } else if max > nums[i] {
//倒序遍历数组，找到一个元素 x, 令 x 后面的元素至少有一个大于x，然后对x后面的元素做升序排列
                bubbleSort(nums: &nums, range: (i + 1...nums.endIndex - 1))
//交换 x 和 第一个大于x的值  
                for j in (i + 1..<nums.endIndex) {
                    if nums[i] < nums[j] {
                        (nums[i], nums[j]) = (nums[j], nums[i])
                        return
                    }
                }
            }
        }
    }
    bubbleSort(nums: &nums, range: (0...nums.endIndex - 1))
}
}
```