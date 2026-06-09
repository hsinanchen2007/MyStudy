### 解题思路
列表中直接append了lst之后，保存的是lst的地址，而不是当前值。但我们需要当前值，所以使用浅拷贝复制当前列表的值即可

### 代码

```python3
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans, lst = [], []

        def DFS(current_pos):
            if sum(lst) == target:
                ans.append(copy.copy(lst))      # 涉及到底层实现，记住就好
            elif sum(lst) < target:
                for i in range(current_pos, len(candidates)):
                    lst.append(candidates[i])
                    DFS(i)
                    lst.pop()       # 回溯


        DFS(0)
        return ans
```