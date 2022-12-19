新人一枚，欢迎大神指正，提升代码能力！
可以把Excel表序号抽象成26进制，
利用ASCII码转换的好处是26个大写的字母映射的数字也是连续的；
ASCII：[http://c.biancheng.net/cpp/html/3415.html](http://c.biancheng.net/cpp/html/3415.html)

思路大致如下：
- 定义三个变量第一个是字符串s的长度，方便指针i使用 \ 第二个是res保存结果 \ 第三个是由于位数造成的26的幂保存为time
- 倒序遍历字符串（个人认为正序倒序貌似没有区别？）
- res每次由字符串转化为ASCII码的数字与26的time次幂取积后自增
- 由于是倒序所以幂的次数每次会+1

```
class Solution:
    def titleToNumber(self, s: str) -> int:
        length = len(s) 
        res = 0
        time = 0
        for i in range(length-1,-1,-1):
            res += (ord(s[i])-64)*26**time
            time += 1
        return res
```


