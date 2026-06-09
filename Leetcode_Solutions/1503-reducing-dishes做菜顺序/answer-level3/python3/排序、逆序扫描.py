### 解题思路

满意度越大的肯定是放到后面越好，所以先拍一下序


然后逆序扫描，维护一个和。如果加上当前元素，带来的增益是正的，那么就加，否则就不加。


### 代码

```python3
class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort()
        t_s = 0
        res = 0
        for i in satisfaction[::-1]:
            if t_s + i > 0:
                t_s += i
                res += t_s
        return res
```