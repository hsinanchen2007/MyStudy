### 解题思路
感谢题解提供思路。迭代使用的堆栈一定要保存begin值，从而避免重复！
最终超过96%的用户

### 代码

```python3
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
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
                    stack.append((temp - candidates[i], tempVol, i))
                else:
                    break
        return ret
```