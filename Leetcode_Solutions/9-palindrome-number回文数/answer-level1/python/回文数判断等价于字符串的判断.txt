**原始字符串与倒过来的字符串进行对比**
1. 一种是正整数的判断：需要判断这个数字和它倒过来的数字是否相同，可以把这个正整数化为字符串的形式，然后在求它的倒过来形式，判断二者是否相同；
2. 第二种是负整数的判断：同样倒过来的字符串是否和其自身相同，例如-123和321-本身不相同
```python
class Solution:
    def isPalinrome(self,x):
        str_x = str(x)
        str_x_palinrome = str_x[::-1]
        return str_x == str_x_palinrome
```


