### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sumNums(self, n: int) -> int:
        # 递归解法，但是不能if
        # res = 0
        # if n == 1:
        #     return 1
        # res += n + self.sumNums(n-1)
        # return res
        # return n and n + self.sumNums(n-1)

        return (pow(n,2)+n)>>1
```