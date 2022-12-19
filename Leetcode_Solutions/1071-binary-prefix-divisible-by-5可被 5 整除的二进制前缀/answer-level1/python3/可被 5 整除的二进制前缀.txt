### 解题思路
我的思路：看代码叭
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)

### 代码

```python
class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        result = []
        sums = 0
        for i in range(len(A)):
            if i == 0:
                sums = A[i]
            else:
                sums = sums*2 + A[i]
            if sums % 5 == 0:
                result.append(True)
            else:
                result.append(False)
        return result
```