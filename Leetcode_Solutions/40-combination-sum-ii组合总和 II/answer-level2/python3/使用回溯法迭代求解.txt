### 解题思路
和上一题思路相同，不同点在于begin需要+1。
还有，去重这里，因为上一题可以随意使用重复元素，因此不需要在进行去重。
这道题则需要在最后进行一次去重。

### 代码

```python3
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        stack, ret, n = [(target, [], 0)], [], len(candidates)
        while stack:
            temp, vol, begin = stack.pop(0)
            for i in range(begin, n):
                tempVol = vol.copy()
                if temp - candidates[i] == 0:
                    tempVol.append(candidates[i])
                    ret.append(tempVol)
                    break
                elif temp - candidates[i] > 0:
                    tempVol.append(candidates[i])
                    stack.append((temp - candidates[i], tempVol, i + 1))
                else:
                    break
        temp = []
        for i in ret:
            if i not in temp:
                temp.append(i)
        return temp
```