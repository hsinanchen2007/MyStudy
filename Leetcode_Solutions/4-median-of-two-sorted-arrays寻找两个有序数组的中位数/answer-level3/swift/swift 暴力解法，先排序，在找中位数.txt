### 解题思路
先排序，在找中位数

### 代码

```swift
class Solution {
    func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {
        //        执行用时 : 156 ms , 在所有 swift 提交中击败了 13.47% 的用户
        //        内存消耗 : 21.4 MB , 在所有 swift 提交中击败了 6.06% 的用户
        //暴力解法 
        var sortedNums = [Int]()
        sortedNums.append(contentsOf: nums1)
        var offset = 0
        for i in 0..<nums2.count { //插入排序
            var isOp = false
            for j in 0..<nums1.count {
                if nums2[i] < nums1[j] {
                    sortedNums.insert(nums2[i], at: j+offset)
                    offset += 1
                    isOp = true
                    break
                }
            }
            if !isOp {
                sortedNums.insert(nums2[i], at: nums1.count + offset)
                offset += 1
            }
        }
        let count = sortedNums.count
        if count % 2 == 0 {
            return Double((sortedNums[count/2] + sortedNums[count/2 - 1])) * 0.5
        }else{
            return Double(sortedNums[(count-1) / 2])
        }
    }
}
```