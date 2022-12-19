### 解题思路
统计整数各个数字的出现次数
然后计算2的次幂的数字，二者一致说明可以完成转化

### 代码

```python3
class Solution:
    def reorderedPowerOf2(self, N: int) -> bool:
        n = str(N)
        c = collections.Counter(n)
        leng = len(n)
        i = 0
        flag = False
        while 2 ** i < 10 ** leng:
            a = collections.Counter(str(2 ** i))
            if a == c:
                flag = True
                break
            i += 1
        return flag  
```