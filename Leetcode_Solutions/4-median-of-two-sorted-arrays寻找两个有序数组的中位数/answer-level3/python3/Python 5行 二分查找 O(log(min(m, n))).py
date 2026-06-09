```Python []
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        a, b, m = *sorted((nums1, nums2), key=len), (len(nums1) + len(nums2) - 1) // 2
        self.__class__.__getitem__ = lambda self, i: m-i-1 < 0 or a[i] >= b[m-i-1]
        i = bisect.bisect_left(self, True, 0, len(a))
        r = sorted(a[i:i+2] + b[m-i:m-i+2])
        return (r[0] + r[1 - (len(a) + len(b)) % 2]) / 2
```
- 本题思路与官方题解类似，时间复杂度O(log(min(m, n)))，没看过的话建议先大体了解一下
- python 中 bisect 模块针对的是 list, 如果直接构造 list，时间复杂度为 O(min(m, n))，因此我们修改当前类的魔法方法伪造 list
- 在一个有序递增数列中，中位数左边的那部分的最大值一定小于或等于右边部分的最小值
- 如果总数组长度为奇数，m 代表中位数的索引，否则 m 代表用于计算中位数的那两个数字的左边一个。比如输入为[1,2]，[3]，那么m应该为[1,2,3]中位数2的索引1，如果输入为[1,3]，[2,4]，那么m应该为[1,2,3,4]中2的索引1
- 使用二分搜索找到 m 对应的值在a或b中对应的索引，也就是说，我们要找的中位数或中位数左部应该是 a[i] 或者 b[m-i]
- bisect.bisect_left 搜索列表中保持列表升序的情况下，True应该插入的位置（从左侧），比如 [F,F,T] 返回 2，[F,F] 返回 2
- 这里保证 a 是 nums1 和 nums2 中较短的那个，是为了防止二分搜索的时候索引越界
- sorted返回一个list，假设返回值是 [nums1, nums2]，那么前面加个 * 号就代表取出列表的所有内容，相当于一个迭代器，结果相当于直接写 nums1, nums2
```python
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) < len(nums2):
            a, b = nums1, nums2
        else:
            a, b = nums2, nums1
        m = (len(nums1) + len(nums2) - 1) >> 1
        
        l, h = 0, len(a)
        while l < h:
            i = (l + h) >> 1
            if m-i-1 < 0 or a[i] >= b[m-i-1]:
                h = i
            else:
                l = i + 1
        
        r = sorted(a[l: l + 2] + b[m - l: m - l + 2])
        return (r[0] + r[1 - (len(a) + len(b)) % 2]) / 2
```
