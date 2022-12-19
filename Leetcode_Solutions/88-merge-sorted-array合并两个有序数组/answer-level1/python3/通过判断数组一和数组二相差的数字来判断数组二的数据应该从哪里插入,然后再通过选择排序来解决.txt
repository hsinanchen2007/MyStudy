### 解题思路
因为长度是永远足够的,所以不用担心越界问题.
那么两个数组相差的长度就是开始插入的索引位置,通过pop方法删除并获取数组二中被删除的数据,再插入数组一中
结束后使用选择排序即可

### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        for i in range((len(nums1)-len(nums2)),len(nums1)):
            if nums1[i]==0:
                num=nums2.pop(0)
                nums1[i]=num
        for i in range(len(nums1)):
            key=i
            for j in range(i+1,len(nums1)):
                if nums1[key]>nums1[j]:
                    key=j
            num=nums1[i]
            nums1[i]=nums1[key]
            nums1[key]=num
```