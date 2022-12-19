### 解题思路
直接用的sort函数了，感觉还是需要研究下这两个有序列表的合并

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        # 构造一个列表出中位数的函数
        def median(data):
            half = len(data) // 2
            # 用取反来找到位置
            return (data[half] + data[~half])/2
        if nums1 is []:
            return median(nums2)
        if nums2 is []:
            return median(nums1)
        all_list = nums1 + nums2
        all_list.sort()
        return median(all_list)
```