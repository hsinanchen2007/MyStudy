### 解题思路
执行用时 :
376 ms
, 在所有 python3 提交中击败了
61.89%
的用户
内存消耗 :
13.7 MB
, 在所有 python3 提交中击败了
27.92%
的用户
### 代码

```python3
class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        str_A=""
        for each_A in A:
            str_A+=str(each_A)
        int_res=int(str_A)+K
        lsit_res=list(str(int_res))
        res=[]
        for each_res in lsit_res:
            res.append(int(each_res))
        return res
```