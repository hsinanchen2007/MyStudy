python实现了扁扁熊的思路, 添加了自己的理解


```
class Solution:
    def findMedianSortedArraysB(self, nums1, nums2):
        '''
        1. 两个数组是有序的, 所以分别对两个数组采用二分法
            a. 两个数组被分别进行二分, 所以一共有4个子数组n1l, n1r; n2l, n2r
            b. !! 中间分一下，总体的中位数肯定是在二分后4块数据中的两块
        2. 分割点左右两边的值的边界情况:
            a, n1左值 > n2右值: 总体的中位数是两个数组合并后的中位数,
            此时num1的中位数大于等于合并后的中位数, 所以num1要查小的部分 n1l,
            此时num2的中位数小于等于合并后的中位数, 所以num2要查大的部分 n2r,
            b, n2左值 > n1右值: 类似于a.
            c, 左值 < 右值: 因为数组是有序的, 所以, 左边的个数=右边的个数, 二分点就是中位数的位置
        3. 数组长度是偶数的, 分割点左边的值: nums1[(c1 - 1) >> 1]
                            分割点右边的值: nums1[c1 >> 1]
           是奇数时, 二者是相等的
        '''
        n, m = len(nums1), len(nums2)
        # 为防止索引溢出, 将长度小的数组放到nums1
        if n > m:
            nums1, nums2 = nums2, nums1
            n, m = m, n
        # num1分割点左边的值, num1分割点右边的值, num2分割点左边的值, num2分割点右边的值
        n1left, n1right, n2left, n2right = 0, 0, 0, 0
        # high设为n * 2, 保证了第一次二分时, 从nums1的末尾开始遍历
        low, high = 0, n * 2

        while low <= high:
            # 待比较的num1的长度, 以此得到num1的二分点
            c1 = low + ((high - low) >> 1)
            # 待比较的num2的长度
            c2 = m + n - c1
            # 6,7 & 3,4,5: nums1已经比较完, 说明都比中位数大, 中位数在nums2,
            # num1分割点左边的值是空了, 不会参与到中位数的计算中
            n1left = -float("inf") if c1 == 0 else nums1[(c1 - 1) >> 1]
            # 11,12 & 3,4: nums2已经比较完, 说明都比中位数小, 中位数在nums1,
            # num2分割点右边的值空了, 不会参与到中位数的计算中
            n2right = float("inf") if c2 == 2 * m else nums2[c2 >> 1]
            # num1的中位数大于等于合并后的中位数, 所以num1要查小的部分 n1l
            # 11,12 & 0,1,3:
            if n1left > n2right:
                high = c1 - 1
                continue

            n1right = float("inf") if c1 == 2 * n else nums1[c1 >> 1]
            n2left = -float("inf") if c2 == 0 else nums2[(c2 - 1) >> 1]
            if n2left > n1right:
                low = c1 + 1
            else:
                break
        # 处理数组长度为偶数/奇数的边界问题
        return (max(n1left, n2left) + min(n1right, n2right)) / 2.0
```