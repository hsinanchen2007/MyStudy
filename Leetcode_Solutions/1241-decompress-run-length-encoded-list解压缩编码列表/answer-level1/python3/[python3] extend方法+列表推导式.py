### 解题思路
此处撰写解题思路

执行用时 :
52 ms
, 在所有 Python3 提交中击败了
75.54%
的用户
内存消耗 :
13.5 MB
, 在所有 Python3 提交中击败了
100.00%
的用户
### 代码

```python3
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        ans = []
        for i in range(0, len(nums), 2):
            # extend()方法：Extend list by appending elements from the iterable.
            # 使用列表推导式直接生成要附加的列表
            ans.extend([nums[i+1] for x in range(nums[i])])
        return ans

```