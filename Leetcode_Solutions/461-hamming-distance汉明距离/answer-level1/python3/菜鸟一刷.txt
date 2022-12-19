### 解题思路
按位异或

### 代码

```python3
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        n=x ^ y
        sum=0
        while(n!=0):
            sum=sum+n%2
            n=n//2
        return sum

```