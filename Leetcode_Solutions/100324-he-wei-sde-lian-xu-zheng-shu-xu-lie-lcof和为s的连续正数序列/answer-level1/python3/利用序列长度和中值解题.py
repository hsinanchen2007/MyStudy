### 解题思路
设连续正数序列的左右端点分别为x和y，则序列累加和为s=(y+x)(y-x+1)
设序列中正数个数为n，则序中值mid=target//n（向下取整）,且有n=y-x+1
易得：
1.当n为奇数时，y+x=2*mid
  则s=mid*n
2.当n为偶数时，y+x=2*mid+1，从而可得s的表达式

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target):
        """
        type target: int
        rtype: List[List[int]]
        """
        res = []
        n = (target+1) // 2  # 序列长度
        mid = target // n  # 序列均值
        while n >= 2:
            if mid <= (n-1) // 2:
                n -= 1
                mid = target // n
                continue
            if n % 2:  # 序列长度为奇数
                s = mid * n
                if s == target:
                    res.append([i for i in range(mid-n//2, mid+n//2+1)])
            else:  # 序列长度为偶数
                s = (2*mid+1) * n // 2
                if s == target:
                    res.append([i for i in range(mid-n//2+1, mid+n//2+1)])
            n -= 1
            mid = target // n
        return res
```