### 解题思路
看示例这三个部分是按数组A顺序排列的，所以只是对A进行切分
三个部分和相等，所以每部分的和是sum(A)/3
满足条件从A[0]开始累加求和直到等于sum(A)/3,继续累加求和直到等于sum(A)/3*2
不满足则返回false

### 代码

```python
class Solution:
    def canThreePartsEqualSum(self, A):
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
        while j + 1 < n:  # 需要满足最后一个数组非空
            cur += A[j]
            if cur == target * 2:
                return True
            j += 1
        return False


```