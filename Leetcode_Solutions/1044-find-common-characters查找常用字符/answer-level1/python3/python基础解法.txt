解题思路：hash数组，统计每个字母出现的次数，求交集。
代码：
```
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        result = list()
        for w in set(A[0]):
            count = [x.count(w) for x in A]
            a = w * min(count)
            for i in a:
                result.append(i)
        return result
```
