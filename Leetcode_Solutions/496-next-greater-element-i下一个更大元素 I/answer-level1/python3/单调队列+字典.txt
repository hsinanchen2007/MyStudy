### 解题思路
1. 解题目标：
- nums1 第i个元素，在nums2中，(i,len(nums2))区间中，比nums1[i]大的第一个数
2. 解题思路：
- 暴力法：直接调list的max或双重for遍历
- 单调队列：
    - 因为nums1是nums2的子集，nums2元素不重复
    - 维护nums2每个元素的下一个最大值，字典记录

### 代码

```python3

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        kv = dict()
        #单调递减队列
        s = []
        res = []
        #从后往前找每个元素的下一个最大值
        for i in range(len(nums2)-1,-1,-1):
            while s and s[-1] <= nums2[i]:
                s.pop()
            if s:kv[nums2[i]] = s[-1]
            else:kv[nums2[i]] = -1
            s.append(nums2[i])
        for i in nums1:
            res.append(kv[i])
        return res

```