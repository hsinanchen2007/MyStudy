### 解题思路
定义一个字符串c 存放 列表转换成的数字
例如 `digits=[1,2,3]`
c="123"
然后c+1  = 124
然后再把c转换成 字符串 
然后 输出
### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        
        c=''.join(str(i) for i in digits)
        c=str(eval(c)+1)
        return [eval(i) for i in c]
        
```