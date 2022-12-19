### 解题思路
官方题解中单调栈的想法很美妙！
单调栈在习题 [155. 最小栈](https://leetcode-cn.com/problems/min-stack/) 中也被提到并应用非同步保持当前已知的最小值。




### 代码

```python3
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) == 0:
            return []
        n = len(nums2)         # 这一题一开始一点思路都没有。只有暴力法
        ## 单调栈 预处理 nums2
        D = dict()  # 存储 nums2 中提取出的信息
        stack = []
        for x in nums2:
            if len(stack) == 0 or stack[-1] > x:
                stack.append(x)
            elif stack[-1] < x:  # stack 不为空，且小于 x，不会有等于
                while len(stack)>0 and stack[-1] < x:
                    D[stack.pop()] = x 
                stack.append(x)
        # 赋值 -1
        while len(stack)>0:
            D[stack.pop()] = -1
        result = []
        for x in nums1:
            result.append(D[x])
        return result
```

##### 暴力方法
``` python 
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) == 0:
            return []
        n = len(nums2)         # 这一题一开始一点思路都没有。只有暴力法

        result = []
        for x in nums1:
            for i in range(n):
                if x==nums2[i]:
                    j = i+1
                    while j<n:
                        if nums2[j]>x:
                            result.append(nums2[j])
                            break
                        j += 1
                    if j == n:
                        result.append(-1)
        return result
```