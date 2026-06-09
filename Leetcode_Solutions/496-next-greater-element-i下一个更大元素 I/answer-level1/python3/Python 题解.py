```
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = [] # 存储答案
        for n1 in nums1: # 遍历 nums1
            temp = -1 # 默认填入 -1 (未找到该值)
            for n2 in nums2[nums2.index(n1):]:  # 在 nums2 中找到 n1 的位置，并截取列表
                if n2 > n1:
                    temp = n2 # 找到 n1 对应的答案
                    break
            ans.append(temp) # 添加答案
        return ans
```
