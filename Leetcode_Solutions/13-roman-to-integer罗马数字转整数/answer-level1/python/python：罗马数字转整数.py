### 解题思路
方法一：
字典完成转化对应，遍历字符串，循环相加，如果上一个字符比当前小，则减去二倍较小字符
优化：增加字典条目，字典是哈希查找，几乎不增加时空复杂度，但需要注意双字符判断
```python3
dic={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000,'IV':4,'IX':9,'XL':40,'XC':90,'CD':400,'CM':900}
```

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        dic={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        sum=0
        pre=0
        for i in s:
            cur=dic.get(i)
            sum+=cur-pre*2 if pre<cur else cur
            pre=cur
        return sum 
```

### 求助
我认为正则表达式可以更简单地完成，但是还没有想明白

20200315
感谢@复苏的兵马俑 帮我解答，没有绑定手机，只好在这里回复了