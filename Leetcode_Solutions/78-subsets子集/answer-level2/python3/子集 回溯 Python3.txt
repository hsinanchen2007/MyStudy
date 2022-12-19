### 解题思路
解法1：递归，[1, 2]的子集是[[],[1],[2],[1,2]]，那么[1,2,3]的子集是[1,2]的子集每个都加上3的集合并上[1,2]的子集[[3],[1,3],[2,3],[1,2,3]] + [[],[1],[2],[1,2]]

解法2：回溯
1. 需要注意的是，因为与顺序无关，也就是说[1,2]和[2,1]是一样的，因此每次选择时候的可选列表，都只有nums中当前值后面的值，因此我们用一个start来记录当前值在nums中后一个的位置
2. 为了便于比较，我们每次都是从nums中取值进行操作

### 回溯代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:

        def backtrack(nums, track, start):
            # 进入节点前进行的操作
            # 将当前路径的拷贝加入res
            res.append(track.copy())  # 前序遍历
            
            for i, num in enumerate(nums): 
                # 选择列表：1不在track中的值 2在num后面的值
                if i >= start and num not in track:  
                    # 做选择
                    track.append(num)
                    # 进入下一个选择
                    backtrack(nums, track, i+1)
                    # 撤销选择
                    track.pop()
        
        res = []
        backtrack(nums, [], 0)
        return seen
                
```