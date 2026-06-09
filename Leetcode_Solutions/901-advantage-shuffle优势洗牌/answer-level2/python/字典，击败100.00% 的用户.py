### 解题思路
对于每一个b，如果有a比它大，找到满足条件的最小的a然后pop出A，放在结果数列的与b在B中index一致的位置。
全部对应之后，没有对应到A中任何数字的位置从剩余的A中的元素里随便分配。

为了避免超时，也就是O（n^2）复杂度，将A、B按程序排序并使用dict记录B原来的元素与位置。

### 代码

```python3
from collections import defaultdict
class Solution:
    def advantageCount(self, A: List[int], B: List[int]) -> List[int]:
        res = [-1]*len(A)
        A.sort()
        b2i = defaultdict(list)
        for i,b in enumerate(B):
            b2i[b].append(i)
        B.sort()
        s_i = 0
        for b in B:
            if b >= A[-1]:
                continue
            for i in range(s_i,len(A)):
                a = A[i]
                if b <a:
                    j = b2i[b].pop()
                    res[j] = A.pop(i)
                    break
            s_i = i

        for i,x in enumerate(res):
            if x<0:
                res[i] = A.pop()
        return res
                
```