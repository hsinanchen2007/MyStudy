### 解题思路
1、去除空格：注意是有返回值的，所以要拿一个值去接
```
s = s.strip() ##去掉收尾的空格
s = s.lstrip() ##去除左边的空格
s = s.rstrip() ##去除右边的空格
```
2、split用法
2.1默认什么参数都不加话，就是默认用空格去分隔，无论中间有几个空格，都一样，都分隔了。
2.2 有参数：
```
s = s.split(",",1) ##在s中中逗号，只分隔一次，eg: int:"a,b,c" out:"a","b,c"
```
3、join：是将list抓换成字符串的用法，双引号里表达的是以什么形式来组合list中的值，此处是用空格来组合。


### 代码

```python3

class Solution:
    def reverseWords(self, s: str) -> str:
        ##先去掉收尾的空格
        s = s.strip()
        ##按照空格分隔
        s = s.split()
        ##反转字符
        s = s[::-1]
        ##连接输出
        return " ".join(s)

```