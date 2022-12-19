![image.png](https://pic.leetcode-cn.com/df25be9da7a29ca7948f8082032bc6a75b184132300c614e7577d110e035618b-image.png)

40ms，98%，仅供参考。

直接打包排序从后往前替换就得了，判断也行，replace也行，这里用的是replace。

python的系统函数和切片的优化程度都很高，直接用也也不会显著提升运行时间，尽管复杂度可能看起来会高一些。

```python
class Solution:
    def findReplaceString(self, S: str, indexes: List[int], sources: List[str], targets: List[str]) -> str:
        for i, s, t in sorted(zip(indexes, sources, targets) , reverse = True):
            S = S[: i] + S[i: i + len(s)].replace(s, t) + S[i + len(s): ]
        return S
```
