一、Clarification

无特别需要注意的边界条件

二、Possible solutions

1、常规双指针解法

指针 point_s 指向 s 第一个字符，指针 point_t 指向 t 第一个字符。逐一判断 point_s 所指向的字符是否在 t 中存在。

如果 s[point_s] != t[point_t] , point_t = point_t + 1, 继续对比t的下一个字符，s的第point_s个字符是否在t中

如果 s[point_s] == t[point_t] , point_s = point_s + 1 , point_t = point_t + 1, 继续对比s的下一个字符

2、借助迭代器和生成器

借助python迭代器和生成器的特性，可以进一步简化代码相应的不太好理解（相关说明见下方代码）


## 常规双指针解法

```python
# @author:leacoder 
# @des:  双指针解法 判断子序列

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
    	# 判断 s 是否为 t 的子序列。
    	# 指针 point_s 指向 s 第一个字符，指针 point_t 指向 t 第一个字符。逐一判断 point_s 所指向的字符是否在 t 中存在。
    	point_s = 0
    	point_t = 0
    	length_s = len(s)
    	length_t = len(t)
'''
1、如果 s[point_s] != t[point_t] , point_t = point_t + 1, 继续对比t的下一个字符，s的第point_s个字符是否在t中
2、如果 s[point_s] == t[point_t] , point_s = point_s + 1 , point_t = point_t + 1, 继续对比s的下一个字符。
'''
    	while point_s < length_s and point_t < length_t:
    		if s[point_s] == t[point_t]:
    			point_s = point_s + 1
    		point_t = point_t + 1
    	# 最后通过point_s是否与length_s相等判断s 是否为 t 的子序列。
    	return point_s == length_s
```

## 借助迭代器和生成器

```python
# @author:leacoder 
# @des:  借助迭代器和生成器 判断子序列

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
    	# 判断 s 是否为 t 的子序列。
    	b = iter(t)  # 迭代器
    	return all(((i in b) for i in s ))
```

说明：

为了便于理解代码扩展分析

```python
def is_subsequence(s, t):
    b = iter(t)   # 把 t 转化成了一个迭代器
    print(b)
    gen = (i for i in s)  # 产生一个生成器， 这个生成器可以遍历对象 s
    print(gen)
    for i in gen:
        print(i)
    gen = ((i in b) for i in s)
    print(gen)
    for i in gen:
        print(i)
    return all(((i in b) for i in s))
```

![借助迭代器和生成器.png](https://pic.leetcode-cn.com/ff4758f320a2313934b365379d596baffd3d3cefb372035fe974817a02e4d049-image.png)

b = iter(b) ， 把列表 b 转化成了一个迭代器
gen = (i for i in s) 产生一个生成器， 这个生成器可以遍历对象 s，能够输出 1, 3, 5。
(i in b)可以联想到 for in 语句。

(i in b) ， 大致等价于

```python
while True:
    val = next(b)
    if val == i:
        yield True
```

巧妙地利用了成器的特性， next() 函数运行的时候， 保存了当前的指针。

那么((i in b) for i in s)可以理解为：遍历s中元素 i，并在b中查找元素 i 是否存在。
由于next() 函数和yield 生成器的特性,如果 b 存在 i 返回True并保存当前指针不存在返回False
（下一次查找从保存的指针开始继续查找，直到s 或者 b 遍历结束），这些True或False产生一个迭代器。

最后的 all() 函数，判断一个迭代器的元素是否全部为 True， 如果是则返回 True， 否则就返回 False。