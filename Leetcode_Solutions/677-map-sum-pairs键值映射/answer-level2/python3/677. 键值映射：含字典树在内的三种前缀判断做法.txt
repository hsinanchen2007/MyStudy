三种方法本质都是前缀的存储或判断，前两种效率区别不大，最后一种是字典树python的常规实现方法。



**方法一：** 把单词的值保存进字典d，并且把单词存进前缀字典p，然后把前缀指向的单词求和就可以了，但空间相对比较大。

![image.png](https://pic.leetcode-cn.com/adcba194cd47ff695af27d71e982ac97ab417d9c8425a6065a7019beaf98e5af-image.png)

```python [1]
class MapSum:

    def __init__(self):
        self.d = {}
        self.p = collections.defaultdict(set)

    def insert(self, key: str, val: int) -> None:
        self.d[key] = val
        for i in range(len(key)):
            self.p[key[: i + 1]].add(key)

    def sum(self, prefix: str) -> int:
        return sum(self.d[key] for key in self.p[prefix])
```
```
样例的两轮操作的前缀字典：
self.p = defaultdict(<class 'set'>, {'a': {'apple'}, 'ap': {'apple'}, 'app': {'apple'}, 'appl': {'apple'}, 'apple': {'apple'}})
self.p = defaultdict(<class 'set'>, {'a': {'apple', 'app'}, 'ap': {'apple', 'app'}, 'app': {'apple', 'app'}, 'appl': {'apple'}, 'apple': {'apple'}})
```


**方法二：** 利用系统前缀判断函数startswith()，在字典里搜索前缀的对应单词并求和，最简单直接，效率也不是太差，除了存值没有多余的空间。

![image.png](https://pic.leetcode-cn.com/4c87f311e721cc933c2b17e3675342989a37c99bd415f892e22d3acf60e44f22-image.png)

```python [2]
class MapSum:

    def __init__(self):
        self.d = {}

    def insert(self, key: str, val: int) -> None:
        self.d[key] = val

    def sum(self, prefix: str) -> int:
        return sum(self.d[s] for s in self.d if s.startswith(prefix))
```

**方法三：** 字典树，把单词的值存进字典树，然后对前缀之后的子树进行深搜求和，时间理论上最快。

![image.png](https://pic.leetcode-cn.com/7ad6a2fc49e307e263d6959c811c2ead6e6c979a2432dbbec419fb1075308b27-image.png)

```python [3]
class MapSum:

    def __init__(self):
        self.d = {}

    def insert(self, key: str, val: int) -> None:
        t = self.d
        for c in key:
            if c not in t:
                t[c] = {}
            t = t[c]            #字典迭代
        t['val'] = val          #迭代终点赋值

    def sum(self, prefix: str) -> int:
        t = self.d
        for c in prefix:
            if c not in t:
                return 0        #判断前缀是否存在
            t = t[c]
        ans = 0
        def dfs(t):
            for c in t:
                if c == 'val':
                    nonlocal ans
                    ans += t[c] #前缀求和
                else:
                    dfs(t[c])   #深搜
        dfs(t)
        return ans
```
```
样例的两轮操作的字典树状态：
self.d = {'a': {'p': {'p': {'l': {'e': {'val': 3}}}}}}
self.d = {'a': {'p': {'p': {'l': {'e': {'val': 3}}, 'val': 2}}}}
```
