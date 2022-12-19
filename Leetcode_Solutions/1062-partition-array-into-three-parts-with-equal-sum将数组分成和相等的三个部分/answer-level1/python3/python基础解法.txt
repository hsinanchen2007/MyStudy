### 解题思路
寻找切分点：首先确定和可以被三整除，不然直接返回false，可以被三整除后我们就需要找等于被三整除的节点。遍历整个数组，和等于target就当一个切分点，在找到第二个切分点，注意需要满足第三个为非空，所以第二次循环的时候需要j+1.

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        s = sum(A)
        if s % 3 != 0:
            return False
        target = s // 3
        n, i, cur = len(A), 0, 0
        while i < n:
            cur += A[i]
            if cur == target:
                break
            i += 1
        if cur != target:
            return False
        j = i + 1
        # j+1防止第三个为非空
        while j+1 < n:
            cur += A[j]
            if cur == target * 2:
                return True
            j += 1
        return False
```