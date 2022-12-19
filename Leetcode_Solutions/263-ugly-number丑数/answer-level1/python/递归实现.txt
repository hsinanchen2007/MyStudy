### 解题思路
递归的思路，依次判断num//2、num//3、num//5是否为丑数，只要有一个是丑数，即可返回。

### 代码

```python3
class Solution:
    def isUgly(self, num: int) -> bool:
        if num==1 or num==2 or num==3 or num==5:
            return True
        elif num==0:
            return False
        # 以上为基例
        else:
            for i in [2,3,5]:
                if num%i==0:
                    if self.isUgly(num//i):
                        return True
            return False
```