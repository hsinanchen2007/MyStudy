![image.png](https://pic.leetcode-cn.com/c3cdf1a66b84f38c715389127dbe1a48ba18a397ec1dc025c5b46043ee40920e-image.png)


### 方法一
调用库函数

### 代码

```python3
class Solution:
    def replaceSpace(self, s: str) -> str:
        return s.replace(' ', '%20') 
```


### 方法二
不调用库函数，时间复杂度O(n)，空间复杂度O(n)

### 代码

```python3
class Solution:
    def replaceSpace(self, s: str) -> str:
        s1 = []                         # 设列表
        for cha in s:                   # 遍历字符串
            if cha == ' ':              # 如果是空格，就在列表后面添加%20
                s1.append('%20')        
            else:                       # 如果不是空格，就在列表后面原样添加
                s1.append(cha)
        return ''.join(s1)              # 把列表转为str
```

小技巧：这里用list而不是str直接处理的原因是。str是不可变数据类型，也就是说每在一个str后面加了一个字符，都是新的str。这样导致空间开销太大。