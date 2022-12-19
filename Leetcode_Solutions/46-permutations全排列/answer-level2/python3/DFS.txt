### 解题思路
1. 题目目标：
在以下这个三叉树种寻找结果
![image.png](https://pic.leetcode-cn.com/d0a39a3a5bb01242423b78ad922a3627ff61e528d4df7ee5ac7015157622c372-image.png)
2. 解题思路：
- DFS；回溯算法

### 代码

```python3
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        self.res = []
        self.backtrack(nums,[])
        return self.res
        
    def backtrack(self,nums,track):
        #结束条件
        if len(track) == len(nums):
            self.res.append([i for i in track])
            return
        #选择列表
        for i in nums:
            #做选择
            if i in track:
                continue
            track.append(i)
            self.backtrack(nums,track)
            #向上回溯
            track.pop()






```