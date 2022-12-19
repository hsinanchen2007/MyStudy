### 解题思路
与官方题解类似。
先遍历nums2维护一个递增栈，并将临时结果储存到哈希表中；
然后遍历nums1，找到哈希表中对应的值。

时间复杂度：O(len(nums1)+len(nums2))
空间复杂度：O(len(nums2))

### 代码

```python3
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res=[]
        hashmap={}
        stack=[]
        for i in nums2:
            while stack!=[] and i>stack[-1]:
                temp=stack.pop()
                hashmap[temp]=i
            stack.append(i)
        for i in nums1:
            res.append(hashmap.get(i,-1))
        return res
```