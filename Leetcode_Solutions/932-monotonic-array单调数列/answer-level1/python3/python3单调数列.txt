### 解题思路
一次遍历，两个循环实际只执行其中一个，且遇到转折点直接退出循环

### 代码

```python3
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        if len(A)<3:
            return True
        for i in range(len(A)-1):
            if A[i]>=A[i+1]:
                down=True
            else:
                down=False
                break
        for i in range(len(A)-1):
            if A[i]<=A[i+1]:
                up=True
            else:
                up=False
                break
        return down or up
```

![image.png](https://pic.leetcode-cn.com/32c29de0eb9a907bd926d430b5940068a564ba9dba23e21c59b449798356f77e-image.png)
