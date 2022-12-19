
# 解题思路
两个有序数组，中位数为合起来的排序数组的中间数，数组长为偶数的话，假设为L,中位数就是排序之后的两个数组中合起来的第L/2和L/2+1的和的二分之一，否则为第L/2个数。因此，我们只需要定义一个函数去寻找第k个大的函数即可。题目限制了时间复杂度，因此使用二分查找。如何求解：分别求出第一个和第二个数组的第 k / 2个数 a 和 b，然后比较 a 和 b，当a < b ，说明第 k 个数位于 a数组的第 k / 2个数后半段，或者b数组的 第 k / 2 个数前半段，问题规模缩小了一半，然后递归处理就行。
# 代码
```
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        m = len(nums1)
        n = len(nums2)
        # 处理任何一个nums为空数组的情况
        if m==0:
            if n % 2 != 0:
                return nums2[n//2]
            return (nums2[n//2] + nums2[n//2-1])/2
        if n==0:
            if m % 2 != 0:
                return nums1[m//2]
            return (nums1[m//2] + nums1[m//2 - 1])/2
        Sum = m + n
        # sum为奇数，找第 (sum+1)//2个数
        if Sum%2!=0:
            return self.find_kth(nums1,0,nums2,0,(Sum+1)//2)
        # sum为偶数，找第 sum//2 个数和第sum//2+1个数
        return (self.find_kth(nums1,0,nums2,0,Sum//2)+self.find_kth(nums1,0,nums2,0,Sum//2+1))/2
    # 寻找第k个数的函数
    def find_kth(self,a, s1, b, s2, k):
        # 当a或b超过数组长度，则第k个数为另外一个数组第k个数
        if s1 >=len(a):
            return b[s2 + k - 1]
        if s2 >= len(b):
            return a[s1 + k - 1]
        # k为1时，两数组最小的那个为第一个数
        if k == 1:
            return min(a[s1], b[s2]);
        # mid_a / mid_b分别表示a数组、b数组中第k / 2个数
        if s1 + k // 2 - 1 < len(a):
            mid_a = a[s1 + k // 2 - 1]
        if s2 + k // 2 - 1 < len(b):
            mid_b = b[s2 + k // 2 - 1]
        # 如果a数组的第k / 2个数小于b数组的第k / 2个数，表示总的第
        # k个数位于a的第k / 2个数的后半段，或者是b的第k / 2个数的前半段
        # 由于范围缩小了k / 2个数，此时总的第k个数实际上等于新的范围内的第k - k / 2个数，依次递归
        if (mid_a < mid_b):
            return self.find_kth(a, s1 + k // 2, b, s2, k - k // 2)
        # 否则相反
        return self.find_kth(a, s1, b, s2 + k // 2, k - k // 2)
```
