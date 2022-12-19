### 解题思路
执行用时 :44 ms, 在所有 Python3 提交中击败了61.29%的用户
内存消耗 :13.8 MB, 在所有 Python3 提交中击败了5.22%的用户

需要注意的一个问题是，append()和pop()操作是在原列表上进行的，所以在res.append()的时候，加入的是track.copy()，否则后续pop()操作会影响到res中的结果，最后返回一个空的二维列表

### 代码

```python3
class Solution:

    def permute(self, nums: List[int]) -> List[List[int]]:
        
        res = []
        
        def backtrack(track):  # 输入路径
            if len(track) == len(nums):
                res.append(track.copy())  # 这里需要注意copy()
            
            for i, num in enumerate(nums):
                if num not in track:  # 选择列表 = nums - 路径
                    track.append(num)  # 选择
                    backtrack(track)  # 进入下一个决策树
                    track.pop()
        
        backtrack([])
        return res
        
        
```