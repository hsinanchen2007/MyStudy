### 解题思路
- 如果是丑数，一定可以除以[2,3,5]中的某数，最后结果是1；
- 可以试着整除以2,不能除了就整除以3，然后整除以5；

### 代码

```python3
class Solution:
    def isUgly(self, num: int) -> bool:
        if num==0:
            return False
        for i in [2,3,5]:
            while num%i==0:
                num = num/i
        return num==1
```