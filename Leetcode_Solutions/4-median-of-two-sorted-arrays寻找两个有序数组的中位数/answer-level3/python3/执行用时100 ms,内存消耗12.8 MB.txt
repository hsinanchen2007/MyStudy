# 解题思路
- 要求时间复杂度为`O(log(m+n))`,基本确定使用二分查找
- 重复理解中位数，中位数将数组均分，左边的个数和右边的个数相等
- 假设数组1的长度为m,数组2的长度为n,并且m大于n
    - 如果数组1的中位数比数组2的中位数小，那么总体的中位数一定不会在数组2中位数的右边，
    - 同理，总体中位数一定不会在数组1中位数的左边，
    - 这样就可以数组2删去右边`n/2`个数，数组1删去左边`n/2`个数，两侧删除的数量相同，总体中位数不会发生改变
    - 这就是递归条件，每次都把数组2减半，时间复杂度就是`O(log(min(m,n)))`
- 基线条件：数组2每次减半，最终会剩余一个元素，然后就可以和组数1的中位数比较，最终判断总体中位数。
- 特殊情况：当两个数组中位数相等时，就可以直接判断。由于偶数组的中位数有两个，奇数组中位数只有一个，所以需要分类讨论。

# 实现代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        """寻找两个有序数组的中位数"""
        def nums_median(nums):
            if len(nums) % 2 == 0:
                return (nums[int(len(nums) / 2) - 1] + nums[int(len(nums) / 2)]) / 2
            else:
                return nums[int(len(nums) / 2)]
        # 排除空数组的情况
        if nums1 is None and nums2 is None:
            return None
        elif not nums1:
            return nums_median(nums2)
        elif not nums2:
            return nums_median(nums1)
        if len(nums1) < len(nums2):
            nums1, nums2 = nums2, nums1

        while True:
            m = len(nums1)
            n = len(nums2)
            mleft = nums1[int(m / 2) - 1]
            mmedian = nums1[int(m / 2)]
            mright = nums1[int(m / 2) + 1] if m >= 3 else None
            nleft = nums2[int(n/2)-1]
            nmedia = nums2[int(n / 2)]
            # 基线条件及特殊情况
            if m % 2 == 0:
                if n % 2 == 0:
                    if mleft <= nleft and nmedia <= mmedian:
                        return (nleft + nmedia) / 2
                    elif mleft > nleft and nmedia > mmedian:
                        return (mleft + mmedian) / 2
                else:
                    if n == 1 and nmedia <= mleft:
                        return mleft
                    elif n == 1 and nmedia >= mmedian:
                        return mmedian
                    elif mleft <= nmedia <= mmedian:
                        return nmedia
            else:
                if n % 2 == 0:
                    if nleft <= mmedian <= nmedia:
                        return mmedian
                else:
                    if n ==1:
                        if m == 1:
                            return (nmedia + mmedian) / 2
                        elif nmedia <= mleft:
                            return (mleft + mmedian) / 2
                        elif nmedia >= mright:
                            return (mmedian + mright) / 2
                        elif mleft <= nmedia <= mmedian or mmedian <= nmedia <= mright:
                            return (mmedian + nmedia) / 2
                    elif nmedia == mmedian:
                        return (nmedia + mmedian) / 2
            # 递归条件
            median1 = nums_median(nums1)
            median2 = nums_median(nums2)
            if median1 < median2:
                nums1 = nums1[int(n / 2):]
                nums2 = nums2[:(n-int(n / 2))]
            else:
                nums1 = nums1[:(m-int(n / 2))]
                nums2 = nums2[int(n / 2):]
```