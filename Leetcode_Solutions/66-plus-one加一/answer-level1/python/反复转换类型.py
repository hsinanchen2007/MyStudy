### 解题思路
看到题先想到得是转换类型再计算，想法简单，但是总感觉还有更直接的转换方法。

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        str_=""
        for i in digits:
            str_=str_+str(i)
        num=int(str_)+1
        List1=[]
        for i in str(num):
            List1.append(int(i))
        return List1



```