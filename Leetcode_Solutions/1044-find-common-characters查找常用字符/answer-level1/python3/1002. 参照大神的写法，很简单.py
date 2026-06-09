### 解题思路
看题解中有的大神写的。
1. set(A[0]) 去掉重复的字母，作为统计相同字母的一个搜索范围。（因为只要是所有的字符串中都包含的字母，那么必包含在A[0]中）
2. 循环在每个字符串中统计每一个k出现的个数，以最少的计（因为多了就会在其他的字符串中不出现）
3. 统计出的个数 * k 加到 res 中即为最后的结果
### 代码

```
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        res = []

        if not A:
            return res
        
        key = set(A[0])
        for k in key:
               
            minimum = min(a.count(k) for a in A)
            res += minimum*k
        return res
```