开始想着暴力法，但是又觉得太简单了。尝试了下栈，具体思路和官方题解大同小异。

```
from typing import List

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:

        map={}
        stack =[]
        greater = []
        for i in nums2:
            if not stack or i<=stack[-1]:

                stack.append(i)
            while(stack and i>stack[-1]):
                map[stack.pop()] = i

            stack.append(i)

        while(stack):
            map[stack.pop()] = -1


        for i in nums1:
            res = map.get(i)
            greater.append(res)
        return greater

so = Solution()
print(so.nextGreaterElement([2,4],[1,2,3,4]))

```
