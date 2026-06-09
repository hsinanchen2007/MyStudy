### 解题思路
执行用时 :520 ms, 在所有 Python3 提交中击败了36.35%的用户
内存消耗 :35.5 MB, 在所有 Python3 提交中击败了5.59%的用户

思路：
递归时一个可以优化的点是：
-1+1+1[?1?1]和+1-1+1[?1?1]和+1+1-1[?1?1]都只需要计算[?1?1]之和等于2,
为了避免重复运算，我们需要记录下前面已经计算过的数字之和和位置（也就是我们设计的dfs函数的参数），每次迭代的时候进行判断是否已经算过了（已经算过的用字典存起来）

### 代码

```python3
class Solution:
    
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        seen = {}
        length = len(nums)
        def dfs(i, cnt):
            if i == length:
                if cnt == S:
                    return 1
                else:
                    return 0
            if (i, cnt) in seen:
                return seen[(i, cnt)]
            res = dfs(i+1, cnt+nums[i]) + dfs(i+1, cnt-nums[i])
            seen[(i, cnt)] = res
            return res

        return dfs(0, 0)
        
        
```