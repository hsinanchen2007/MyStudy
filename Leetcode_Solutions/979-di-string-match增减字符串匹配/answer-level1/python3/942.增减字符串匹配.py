### 解题思路
- 'I'意味着当前的数要比下一个数小，（在剩下的数里）选一个最小的数一定没错
- 'D'意味着当前的数要比下一个数大，（在剩下的数里）选一个最大的数一定没错
-  遍历ID字符，最后还剩一个数，放到最后即可（最后一个字符是‘D’,则在两个数中选大的，最后一个数一定比倒数第二个小，没问题！）

### 代码

```python3
class Solution:
    def diStringMatch(self, S: str) -> List[int]:
        a = list(range(0,len(S)+1))
        res = []
        for instruction in S:
            if instruction == "I":
                res.append(a.pop(0))
            else:
                res.append(a.pop())
        res.append(a.pop())
        return res
```