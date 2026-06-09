### 解题思路
1、回溯交换
2、递归
3、库函数

### 代码

#注意理解回溯过程，是硬骨头，可以举个简单的例子逐步跟着代码走一遍，会理解深刻得多。
```python3
class Solution:
    def permutation(self, s: str) -> List[str]:
        self.res=set()
        s=list(s)
        def helper(first,s,n):
            if first==n:
                self.res.add("".join(s))
            for i in range(first,n):
                s[first],s[i]=s[i],s[first]
                helper(first+1,s,n)
                s[first],s[i]=s[i],s[first]    #交换了之后要回溯回来
        helper(0,s,len(s))
        return list(self.res)

```

#直接递归相对来说好理解一点，
#先变子问题-------每一个字母打头再加上剩余字母的全排列，
#再考虑返回什么---子问题的全排列不是一个，而是所有可能排列的集合，所以不能直接返回全排列，而是用，一个tmp字符串去记录每一个排列
#再考虑递归出口---当然是当为空字符串时返回咯。
```python3
class Solution:
    def permutation(self, s: str) -> List[str]:
        self.res=set()
        def helper(s,tmp=""):
            if len(s)==0:
                self.res.add(tmp)
                return
            for i in range(len(s)):
                helper(s[:i]+s[i+1:],tmp+s[i])
        helper(s)
        return  list(self.res)

```

### 解题思路
作弊的库函数方法，面试时也可以让面试官觉得你对编程语言的方法很熟悉，可以是一种方案，但不能只说这一种方案
### 代码

#注意理解回溯过程，是硬骨头，可以举个简单的例子逐步跟着代码走一遍，会理解深刻得多。
```python3
class Solution:
    def permutation(self, s: str) -> List[str]:
        import itertools
        res=[]
        for k in set(itertools.permutations(s)):
            tmp="".join(k)
            res.append(tmp)
        return res

```