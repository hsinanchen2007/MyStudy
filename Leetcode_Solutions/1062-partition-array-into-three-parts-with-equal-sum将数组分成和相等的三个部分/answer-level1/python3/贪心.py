### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        he = 0
        for i in range(len(A)):
            he += A[i]
        if he%3!=0:return False
        he //=3
        ans = 0
        tmp = 0
        for i in range(len(A)):
            tmp += A[i]
            if tmp == he:ans += 1;tmp = 0
        if ans <3:return False
        else:return True
```