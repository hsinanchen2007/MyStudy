### 解题思路
1.find()函数：这种方法利用find的beg属性，动态规划起始位置
2.迭代器每次判断c in t，都会从判断之后的位置开始，因为内部会调用__next__()方法，性能比find方法低，不过比双指针性能高
3.双指针，字符串比较中一般用的比较多，用于动态控制两个字符串的索引位置,这种方法性能比较低，比find方法的性能低多了

    这里介绍个iter()的知识点：
    iter()有两种参数格式：iter(collection),iter(collection,sentinel)
    传1个参数：参数collection应是一个容器，支持迭代协议(即定义有__iter__()函数)，或者支持序列访问协议（即定义有__getitem__()函数），否则会返回TypeError异常。容器包括支持迭代协议或支持序列协议类型，例如列表，元祖，或者生成器

    传2个参数：当第二个参数sentinel出现时，参数callable应是一个可调用对象(实例)，即定义了__call__()方法，当枚举到的值等于哨兵时，就会抛出StopIteration异常。


    原文链接：https://blog.csdn.net/sxingming/article/details/51479039
### 代码

```python
class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
        if s == '':
            return True
        loc = -1
        for i in s:
            loc = t.find(i,loc+1)
            if loc == -1:           
                return False
        return True   

```


```python
class Solution(object):
    def isSubsequence(self, s, t):
       
        t = iter(t)
        return all(c in t for c in s)
        
```


```python
class Solution(object):
    def isSubsequence(self, s, t):    
       
        i,j = 0,0
        while i<len(s) and j<len(t):
            if s[i] == t[j]:
                i += 1
                j += 1
            else:
                j += 1
        return True if i == len(s) else False
```