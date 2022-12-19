### 解题思路
剪枝剪得好，代码跑到老。
与306的区别是，306不需要返回数组，且306不会超过int_max，其他都一样。

剪枝：
（1）因为对应的数字不会超过2^31 -1，对应10位数字，所以在找前两个数字时，最多解析10位字符串。
（2）每次加的结果如果超过int_max也直接返回。

### 代码

```python
class Solution(object):
    def splitIntoFibonacci(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        MAX_INT = 2 ** 31 -1
        def backtracing(path, i):
            if path:
                last_sum = sum(path[-2:])
                if last_sum > MAX_INT: return []
                last_sum_str = str(last_sum)
                if S[i:].startswith(last_sum_str):
                    path.append(last_sum)
                    if i + len(last_sum_str) == len(S):
                        return path[:]
                    return backtracing(path, i + len(last_sum_str))
                return []
            else:
                for j in range(min(10, len(S) - 2)):
                    if j > 0 and S[0] == "0": break
                    for k in range(j + 1, min(j + 11, len(S) - 1)):
                        if k > j + 1 and S[j + 1] == "0": break
                        a, b = int(S[:j + 1]), int(S[j + 1:k + 1])
                        path = [a, b]
                        result = backtracing(path, k + 1)
                        if result:
                            return result
                return []
        return backtracing([], 0)
```