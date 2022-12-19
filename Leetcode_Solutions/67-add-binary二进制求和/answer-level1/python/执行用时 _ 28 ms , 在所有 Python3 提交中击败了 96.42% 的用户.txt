### 解题思路
1行代码ok
1:a,b转十进制
2:a+b
3:a+b转二进制并变str类型
互转十、二进制博文:https://jingyan.baidu.com/article/11c17a2cfb80d6f446e39d8a.html
python就是牛逼
### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return str(bin(int(a,2)+int(b,2)))[2:]
        '''参考博文:如何用python进行二进制，八进制，十进制转换
        网址：https://jingyan.baidu.com/article/                                   11c17a2cfb80d6f446e39d8a.html'''
        
```