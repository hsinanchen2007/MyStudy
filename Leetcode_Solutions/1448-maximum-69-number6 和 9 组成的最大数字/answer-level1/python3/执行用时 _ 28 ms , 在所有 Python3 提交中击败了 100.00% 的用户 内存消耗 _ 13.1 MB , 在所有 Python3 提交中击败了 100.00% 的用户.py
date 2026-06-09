### 解题思路
肯定是把最高位的6换为9结果最大，没有6就不替换
转为字符串，用replace把第一个出现的‘6‘换为‘9’，再转为数字返回
replace可以设置最多替换几个，如果要替换的不存在就不替换也不会报错
### 代码

```python3
class Solution:
    def maximum69Number (self, num: int) -> int:
        return int(str(num).replace('6','9',1))
```