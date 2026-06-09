### 解法1：字典解法
把nums2存成一个字典，键是nums2里的数值，值是其索引位置，遍历nums1，通过查询字典，找到nums2中的对应值的位置，从右边开始遍历，找到比其大的值就将添加，并提前结束该次遍历，遍历结束还没找到，就添加-1

### 代码

```python3
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        hash_table = {}
        res = []
        #将nums存成字典
        for i in range(len(nums2)):
            hash_table[nums2[i]] = i 
        #遍历nums1
        for num in nums1:
            #从遍历值的右侧开始寻找大值
            for i in range(hash_table[num] + 1, len(nums2)):
                if nums2[i] > num:
                    res.append(nums2[i])
                    break
            else:
                res.append(-1)
        return res
                    

```
### 解法2：单调栈解法
这个是参考的[官方给的单调栈解法](https://leetcode-cn.com/problems/next-greater-element-i/solution/xia-yi-ge-geng-da-yuan-su-i-by-leetcode/)

### 代码
```python3
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        hash_table = {}
        stack = []
        res = []
        for n in nums2:
            while stack and stack[-1] < n:
                hash_table[stack[-1]] = n
                stack.pop()      
            stack.append(n)
        #如果遍历完栈内还有元素，其值均存为-1即可
        while stack:
            hash_table[stack[-1]] = -1
            stack.pop()
        
        for nums in nums1:
            res.append(hash_table[nums])

        return res
```