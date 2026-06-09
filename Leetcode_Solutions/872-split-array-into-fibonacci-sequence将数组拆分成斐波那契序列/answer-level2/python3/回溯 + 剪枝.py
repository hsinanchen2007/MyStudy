### 解题思路
主要是回溯过程中的剪枝优化，减去了值大于2 ** 31 - 1和不符合F[i] + F[i + 1] = F[i + 2]的部分。还有就是new_value以'0'开头并且长度大于1的部分，需要注意'0'是符合条件的数字。

### 代码

```python3
class Solution:
    def splitIntoFibonacci(self, S: str) -> List[int]:
        n = len(S)

        res = []

        def backtrack(index, temp):
            if index == n:
                if self._is_fibonacci(temp):
                    res.append(temp)
                return

            for i in range(index, n):
                new_value = S[index:i + 1]
                if int(new_value) > 2 ** 31 - 1:
                    break
                if not (new_value.startswith('0') and len(new_value) > 1):
                    if len(temp) >= 2 and int(new_value) == (temp[-1] + temp[-2]):
                        backtrack(i + 1, temp + [int(new_value)])
                    elif len(temp) < 2:
                        backtrack(i + 1, temp + [int(new_value)])

        backtrack(0, [])

        return res[0] if res else []

    def _is_fibonacci(self, temp):
        if len(temp) < 3:
            return False
        for i in range(2, len(temp)):
            if temp[i] != (temp[i - 1] + temp[i - 2]):
                return False

        return True
```