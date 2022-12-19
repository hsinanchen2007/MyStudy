### 思路
> 逐位比较两个数组`nums1``nums2`的大小，将较小的数值放入新数组`arr`中，同时将源数组向后移动一位。
> 若`arr`的长度达到中位数的位置，则根据奇偶不同取`arr`后两位或者一位计算中位数
```python
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        len_num1 = len(nums1)
        len_num2 = len(nums2)
        pos = (len_num1 + len_num2) // 2 + 1 # 目标位置
        flag = (len_num1 + len_num2) % 2 # 长度奇偶标志
        i = 0
        j = 0
        arr = [] # 待放入数组
        while i < len_num1 and j < len_num2:
            if len(arr) == pos:
                break
            if nums1[i] < nums2[j]:
                arr.append(nums1[i])
                i += 1
            else:
                arr.append(nums2[j])
                j += 1

        while i < len_num1:
            if len(arr) == pos:
                break
            arr.append(nums1[i])
            i += 1

        while j < len_num2:
            if len(arr) == pos:
                break
            arr.append(nums2[j])
            j += 1

        if flag:
            return arr.pop()
        else:
            return (arr.pop() + arr.pop()) / 2
```
