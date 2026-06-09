### 解题思路
此处撰写解题思路
以[2,3,5]依次做除数进行除法运算。
### 代码

```python3
class Solution:
    def isUgly(self, num: int) -> bool:
        for i in [2,3,5]:
            while num%i==0 and num!=0:
                num /=i
        return num==1
```