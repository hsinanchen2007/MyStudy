```
class Solution:
    def lastStoneWeight(self, st: List[int]) -> int:
        while len(st) > 1:
            y = max(st)
            st.remove(y)
            x = max(st)
            st.remove(x)
            if x < y:
                st.append(y - x)
        if len(st) == 0:
            return 0
        else:
            return st[0]
```
执行结果：
通过
显示详情
执行用时 :
40 ms
, 在所有 Python3 提交中击败了
96.81%
的用户
内存消耗 :
13.9 MB
, 在所有 Python3 提交中击败了
100.00%
的用户
