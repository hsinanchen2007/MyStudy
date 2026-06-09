### 解题思路
将数组拆分成奇数组和偶数组
将奇数组和偶数组穿插插入新的数组即可
时间复杂度O(n)

### 代码

```python3
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        ouli = []
        jili = []
        for i in range(len(A)):
            if (A[i]%2==0):
                ouli.append(A[i])
            else:
                jili.append(A[i])
        newlist = []
        for i in range(len(A)//2):
            newlist.append(ouli[i])
            newlist.append(jili[i])
        return newlist
```