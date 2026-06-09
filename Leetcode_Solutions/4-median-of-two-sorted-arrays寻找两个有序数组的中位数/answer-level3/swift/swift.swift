### 解题思路
转化为在两个数组中找第 K 个小的数 

### 代码

```swift
class Solution {
    func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {
        let lenght_n = nums1.count
        let lenght_m = nums2.count
        
        let left = (lenght_n + lenght_m + 1) / 2
        let right = (lenght_n + lenght_m + 2) / 2
        
        
        return Double((getKthNumber(nums1, 0, lenght_n - 1, nums2, 0, lenght_m - 1, left) + getKthNumber(nums1, 0, lenght_n - 1, nums2, 0, lenght_m - 1, right))) / 2.0
    }
    
    func getKthNumber(_ nums1: [Int], _ start1: Int, _ end1: Int, _ nums2: [Int],  _ start2: Int, _ end2: Int, _ k: Int) -> Int {
        let len1 = end1 - start1 + 1;
        let len2 = end2 - start2 + 1;
        
        //保证num1的长度小于num2的长度，这样就能保证如果有数组空了，一定是num1
        if len1 > len2 {
            return getKthNumber(nums2, start2, end2, nums1, start1, end1, k)
        }
        
        //len == 0, 中位数就是nums2的中位数
        if len1 == 0 {
            return nums2[start2 + k - 1]
        }
        
        //k == 1相当于查找最小值（合并后）
        if k == 1 {
            return min(nums1[start1], nums2[start2])
        }
        
        //i,j分别是数组根据k/2计算的下标
        let i = start1 + min(len1, k/2) - 1
        let j = start2 + min(len2, k/2) - 1
        
        if nums1[i] > nums2[j] {
            //偏移nums2的start，相当于去除之前的元素，同时k值更新，减去去除的元素个数
            return getKthNumber(nums1, start1, end1, nums2, j+1, end2, k - (j - start2 + 1))
        }else{
            //偏移nums1的start，相当于去除之前的元素，同时k值更新，减去去除的元素个数
            return getKthNumber(nums1, i+1, end1, nums2, start2, end2, k - (i - start1 + 1))
        }
    }
}
```