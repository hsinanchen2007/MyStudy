
公众号连载leetcode题解，欢迎关注。

![](https://pic.leetcode-cn.com/2a15d78b4b977527a4d95f2bb238db8c82b7d133878dbf168b4b972271818c58.jpg)


题目汇总： [leetcode](http://flypython.com/leetcode/) 


#### 思路

首先，你得理解题意。不确定的东西，需要问或者尝试验证。

比如：这里你可以问面试官字符串s是ASCII还是Unicode字符串，如果是编程平台你可以写测试来判断。

在这里我们假定字符集为ASCII，那如果字符串长度大于128，那肯定是false，不过有限制条件len(s)<=100，那这个判断就不必要了。限制里面还要求不使用额外的数据结构，这就过滤掉了很多的方案。

比如，使用set就一行代码解决

```
class Solution:
    def isUnique(self, astr: str) -> bool:
        return len(astr)== len(set(astr))
```

我们很容易想到hash计数的方法，经过测试，字符串中只出现'a'到'z'，26个小写字母，那只需要一个bool数组，直接统计出现的频率，判断是否重复。

考虑到不使用额外的数据结构，那我们可以尝试使用bitmap，把数组换成一个整型数，按照位上0，1来判断是否重复。

开始我们算出字符离最开始的字符'a'的距离，然后1移动这个距离来表示这个数。后面用一个测试变量来测试p，如果存在则返回False，如果不存在则写入。

具体代码：

```
    def isUnique(self, astr: str) -> bool:
        t = 0
        for c in astr:
            if t & (p := 1 << (ord(c) - ord('a'))):
                return False
            t |= p
        return True

```

在解答中使用了Python3.8的新特性：海象运算符，点击下面的链接，学习使用它。
https://mp.weixin.qq.com/s/3xKdt-26guYHoFb3xP0muw


#### 方案代码
  
解法:
```
class Solution:
    def isUnique(self, astr: str) -> bool:
        t = 0
        for c in astr:
            if t & (p := 1 << (ord(c) - ord('a'))):
                return False
            t |= p
        return True
```


另外还有三种使用数据结构的解法

解法1:

```
class Solution:
    def isUnique(self, astr: str) -> bool:
        return len(astr)== len(set(astr))
        
```

解法2:
```
class Solution:
    def isUnique(self, astr: str) -> bool:
        adict={}
        for value in astr:
            if value in adict.keys():
                return False
            else:
                adict[value]=0
        return True
        
```


解法3:
```
class Solution:
    def isUnique(self, astr: str) -> bool:
        l=[]
        for i in astr:
            if i in l:
                return False
            else:
                l.append(i)
        return True
```

更多详细题解：

https://mp.weixin.qq.com/s/XVAc56PacCM_r7VdS3zm8A