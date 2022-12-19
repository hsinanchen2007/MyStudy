### 解题思路
1. 等和三分，那么就先将数组求和然后三分。如果能被三整除则说明有能被三等分的可能，否则直接返回False。
2. 从头和尾分别逐个加，直到等于前面求到的三分值。此处应注意，头和尾相加的区间不能将数组完全覆盖，否则中间就没值可加了。

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        j,k,total=0,len(A)-1,0
        for i in A:
            total+=i
        summary=total/3
        begin,end=A[j],A[k]
        if int(summary)!=summary:
            return False
        while j<k-1:
            if begin!=summary:
                j+=1
                begin+=A[j]
            if end!=summary:
                k-=1
                end+=A[k]
            if begin==end==summary and j<k-1:
                return True
        return False

```