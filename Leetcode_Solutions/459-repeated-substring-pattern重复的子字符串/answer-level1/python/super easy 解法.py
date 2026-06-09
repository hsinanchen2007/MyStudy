比较容易想到的当然是暴力解法
# 1.暴力枚举
根据字串长度`l`来进行枚举,重复次数为`n//l`,其中`n`为`s`的长度
```python
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)
        return any(s[0:l]*(n//l) == s for l in range(1,n//2+1))
```
# 2.搬运的解法~
考虑由`s+s`构成的字符串并分别去掉第一项和最后一项构成的字符串`T`,即`T=(s+s)[1:-1]`
## 2.1若`s`出现在`T`中
则`s`一定是由重复子串构成的,若不然,即`s`中没有重复子串.假设`s=x1 x2 ... xn`考虑如下的情形
![image.png](https://pic.leetcode-cn.com/f9d612a9dfb79490b00fc4028168a582d1940236dbf2fcc0b6f8080ad69ee9b9-image.png)

由于`s`的长度为`n`,故横跨了两个区域,即存在`k`,使得
`x1 x2 ... xn = xk x(k+1) ... xn x1 x2 ... x(k-1)`
由上面得到
`x1=xk,x2=x(k+1),...,xn=x(k-1)`
也就是说原来的字符串`s=x1 x2 ... xn`可以替换为`s=x1 x2 ... x(k-1) x1 x2 ... x(k-1)`(从xk开始用上面得到的关系进行替换)
从而`s`由重复子串构成,矛盾
## 2.2若`s`不出现在`T`中
若`s`不出现在`T`中,则`s`一定不是由重复子串构成的,这很显然,因为若`s`是由重复子串构成的,即`s=A A ...`,则`T=s+s`至少包含了`A A`,故`s`一定在`T`中
由此得到如下的简单解法
```python
    def repeatedSubstringPattern(self, s: str) -> bool:
        return s in [s+s][1:-1]
```