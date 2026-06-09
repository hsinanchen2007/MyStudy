### 解题思路
首先转换成数字，加一后再保存在list里面

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num=int("".join(str(i) for i in digits))
        num+=1
        res=[]
        while num:
            res.append(num%10)
            num//=10
        return res[::-1]


```