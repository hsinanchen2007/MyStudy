### 解题思路
暴力解法。。。
合并数组，排序
偶数个元素取中间两位的平均
奇数个元素取中间位置元素
### 代码

```swift
class Solution {
    func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {
        var allNums = nums1 + nums2
        allNums.sort()
        if allNums.count % 2 == 0{
            return Double((allNums[allNums.count/2-1] + allNums[allNums.count/2]))/2
        }
        else{
            return Double(allNums[(allNums.count)/2])
        }
    }
}
```