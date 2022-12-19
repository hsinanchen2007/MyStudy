### 解题思路
此处撰写解题思路
算法：一串罗马数字X的值等于：X中所有元素对应的值-2倍的让值减小的数字，比如IV中的I，CM中的C等；
### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        dic = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        vLst = [dic[i] for i in s]
        Bsum = sum(i for i in vLst)
        eLst = []
        for i in range(len(vLst)-1):
            vv = vLst[i] if vLst[i] < vLst[i+1] else 0
            eLst.append(vv)
        Ssum = sum(i for i in eLst)
        return Bsum-2*Ssum
```