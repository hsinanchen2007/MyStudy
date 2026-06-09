# 运行效果
执行用时 :56 ms, 在所有 Python3 提交中击败了63.12%的用户
内存消耗 :13.6 MB, 在所有 Python3 提交中击败了5.78%的用户
# 时间空间复杂度分析
时间复杂度：O(n)
空间复杂度：O(n) 使用了哈希表
### 代码

```python3
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans=[]  #保存返回的结果
        hashset=set(nums1)
        for i in nums2:
            if i in hashset:
                ans.append(i)
                hashset.remove(i)
        return ans
```