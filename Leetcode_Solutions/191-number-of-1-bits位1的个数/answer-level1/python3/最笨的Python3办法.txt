### 解题思路
把输入的数字先二级制化再去掉前面的0b,在使用编历的方法找出每一个1

### 代码

```python3
class Solution:
    def hammingWeight(self, n: int) -> int:
        n=bin(n)[2:]
        number=0
        for num in range(len(n)):
            if n[num]=='1':
                number+=1
        return number
```