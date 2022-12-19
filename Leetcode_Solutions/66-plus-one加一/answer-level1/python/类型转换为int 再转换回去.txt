### 解题思路
直接强制转换类型

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        def num2str(x):
            return str(x)
        num=int(''.join(list(map(num2str,digits))))
        num=num+1
        def str2nums(x):
            return int(x)
        num=list(map(num2str,str(num)))
        return list(map(str2nums,num))
```