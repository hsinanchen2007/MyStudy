### 解题思路
- 先判断是否能被3整除，不能直接返回False
- 遍历列表，更新一个total,一个index列表；如果total等于平均值，total清零；当前index进入列表；
- 最后index列表若等于3，说明分割成3部分了；若小于3，说明分割不到3部分，返回False;
- 若index列表长度大于3，说明被分成了多个部分，将中间的合并，若等于avg，则分割成功，返回True

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        if sum(A)%3!=0:
            return False
        avg = sum(A)//3
        res = []
        total = 0
        for i in range(len(A)):
            total = total + A[i]
            if total == avg:
                res.append(i)
                total = 0
        if len(res)>3:
            return sum(A[res[0]+1:res[-2]+1])==avg
        return len(res)==3

            
```