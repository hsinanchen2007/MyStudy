## 思路
+ 遍历nums2，维护一个递减栈
+ 当得到一个更大的数的时候，将栈里小于它的数都放到哈希表当中
> 举例来说，如果nums2里是3,2,1,4，那么栈前三位都是3,2,1，当遍历到4的时候，发现4比1大，这时候，哈希表里要添加hashmap[1] = 4,hashmap[2] = 4,hashmap[3] = 4。含义是，对于1这个数字而言，右边第一个比它大的数字是4。后面几个同理。
+ 遍历nums1，对每一项查找哈希表，找到第一个比它大的数，并返回一个列表作为答案。如果在哈希表中不存在则返回默认值-1。

## 代码
``` Python
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack, hashmap = list(), dict()
        for i in nums2:
            while len(stack) != 0 and stack[-1] < i:hashmap[stack.pop()] = i
            stack.append(i)
        return [hashmap.get(i,-1) for i in nums1]
```
## 复杂度分析
+ 时间复杂度：$O(M+N)$，其中N为nums1的长度，M为num2的长度
+ 空间复杂度：$O(M)$，其中M为nums2的长度