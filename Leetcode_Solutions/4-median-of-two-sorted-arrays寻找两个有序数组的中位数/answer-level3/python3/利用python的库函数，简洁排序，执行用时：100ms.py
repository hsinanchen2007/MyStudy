### 解题思路
此处撰写解题思路
1.数组合并：直接使用“+”操作合并两个数组
2.将新数组重新排序：利用python自带的sort函数
3.为提高运行速度，提前将新数组长度、新数组中位数的索引提取出来
4.用bit0来判断数组长度的是奇数还是偶数，再计算出中位数的值
### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1 += nums2
        nums1.sort()
        new_len = len(nums1)
        index = new_len//2
        
        if 1 == new_len&1:
            mid = nums1[index]
        else:
            mid = (nums1[index] + nums1[index - 1]) / 2

        return mid
```