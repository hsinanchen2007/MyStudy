class Solution {
        func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {
            let n = nums1.count;
            let m = nums2.count;
            let left = (n + m + 1) / 2
            let right = (n + m + 2) / 2
            let result  = (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) + getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) * 0.5
            print(result)
            return result
        }
        func getKth(_ nums1:[Int], _ start1:Int , _ end1: Int,_ nums2:[Int],_ start2: Int,_ end2: Int,_ k: Int) -> Double{
            let len1 = end1 - start1 + 1
            let len2 = end2 - start2 + 1
            if len1 > len2{
                return getKth(nums2, start2, end2, nums1, start1, end1, k)
            }
            if len1 == 0{
            return Double(nums2[start2 + k - 1])//如果一个数组空了，在新第二个数组的基础上再数原k减去掉个数即k = k - (i - start1 + 1)，也就是再数新k个数
            }
            if k == 1{
            return Double(min(nums1[start1], nums2[start2]))
            }
    
            let i = start1 + min(len1, k / 2) - 1
            let j = start2 + min(len2, k / 2) - 1
    
            if nums1[i] > nums2[j]{
                return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
            }
            else{
                return getKth(nums1,i + 1, end1, nums2, start2, end2, k - (i - start1 + 1))
            }
        }
}