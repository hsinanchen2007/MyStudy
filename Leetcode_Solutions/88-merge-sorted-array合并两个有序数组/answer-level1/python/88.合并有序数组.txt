### 解题思路
del函数，利用数组的有序性，先从后往前把nums1的多余删除掉
append函数，将nums2元素逐个添加到nums1中
sort函数，将新nums1重新排序

### 代码

```python
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        for i in range(len(nums1)-1,m-1,-1):#利用nums1已经是有序的，从后往前把多余的删除
            del nums1[i]
        for i in range(len(nums2)):
            nums1.append(nums2[i])#append函数，将nums2元素逐个添加到nums1中
        return nums1.sort()#sort函数排序

```