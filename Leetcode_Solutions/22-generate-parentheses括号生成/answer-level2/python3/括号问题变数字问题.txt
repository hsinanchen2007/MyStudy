# 括号生成问题

这个解法不算高效，但确实比较容易理解。

## 原题目

> 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

## 题目转化

原题为括号生成，可以尝试对其进行转化，变成别的问题。

### 括号 -> 树

题目限定为有效括号，则可将括号和括号的包含关系，看作树结构中的父子关系。

若根节点不对应括号，其下所有子节点都表示一个括号对。则```(())()```可以看作是三节点树结构，根节点下有两个子节点，第一个子节点下有个孙子节点。

其中括号之间没有区别，所以原问题，相当于

> 给出 n 代表树结构的总节点数（根节点除外），请你写出一个函数，使其能够生成所有可能的树形状

### 树 -> 数字

我们还可以再次简化成为单纯的数字问题。

#### 树节点的层级表示

设根节点的层级数为```0```。每个节点的层级数，是其父节点的层级数加1.

对于树进行深度优先遍历的，遍历到的节点记录层级数字，得到一串数字。

```()```可以表示为```01```，省略根节点，表示为```1```。

之后的表示中，都省略根节点。

括号之间没有区别，我们只需要关注树的形状。而树形状与数字表示是一一对应。

至此，我们可以通过一串数字来表示树形状。

#### 在树上增加节点

总节点数为n的树，可以通过，在总节点数为n-1的树中增加一个节点，来获得。

```()()```可以理解为在```()```的基础上增加一个层级为```1```的节点，表示为```11```。

```(())```可以理解为在```()```的基础上增加一个```2```的节点，表示为```12```。

在```11```，即```()()```，的基础上加一个节点：

* 增加层级为```1```的节点，得到```111```，即```()()()```
* 增加层级为```2```的节点，得到```112```，即```()(())```

在```12```，即```(())```，的基础上加一个节点：

* 增加层级为```1```的节点，得到```121```，即```(())()```
* 增加层级为```2```的节点，得到```122```，即```(()())```
* 增加层级为```3```的节点，得到```123```，即```((()))```

不难发现规律，每个节点的可取值范围为[1, 上一个节点层级数+1]。

通过数字即可以表示出所有的树形状，而树形状问题就变成了：

> 求满足下列所有条件的数字串：
> 
> 1. 长度为n，第i位数字为f(i)
> 
> 2. f(1) = 1
> 
> 3. 1 <= f(i) <= f(i-1) + 1

## 解题

此时，我们只需要对这个数字问题求解，然后把数字转换成括号字符串即可。

### 解决数字问题

循环增加节点

```Python
def generateDigitals(n: int) -> list:
    close_list = [1]
    open_list = []
    for i in range(n - 1):
        for item in close_list:
            for j in range(item % 10 + 1, 0, -1):
                open_list.append(item * 10 + j)
        close_list = open_list
        open_list = []
    return close_list
```

### 数字转树

树节点类型定义

```Python
class Parenthesis:
    def __init__(self):
        self.next = []
```

给定数字X，获取树。方便直接在特定层级操作，我们使用字典来存储节点。
```Python
def generateParenthesisTreeFromX(x: int) -> dict:
    d = defaultdict(list)
    for c in str(x):
        c = int(c)
        if c == 1:
            node = Parenthesis()
            d[c].append(node)
            continue
        if d[c - 1]:
            parent = d[c - 1][-1]
            node = Parenthesis()
            parent.next.append(node)
            d[c].append(node)
    return d
```

### 树转括号

修改一下树节点类的__str__方法

```Python
class Parenthesis:
    def __init__(self):
        self.next = []

    def __str__(self):
        return f'({"".join([str(x) for x in self.next])})'
```

从树生成括号

```Python
d = generateParenthesisTreeFromX(x)
parenthesis_str = ''.join([str(x) for x in d[1]])
```

将转换过程串联起来

```Python
def generateParenthesis(n: int) -> str:
    result = []
    x_list = generateDigitals(n)
    for x in x_list:
        d = generateParenthesisTreeFromX(x)
        result.append(''.join([str(x) for x in d[1]]))
    return result
```

## 完整代码

```Python
# coding:utf-8
from collections import defaultdict


class Parenthesis:
    def __init__(self):
        self.next = []

    def __str__(self):
        return f'({"".join([str(x) for x in self.next])})'


class Solution:

    def generateDigitals(self, n: int) -> list:
        close_list = [1]
        open_list = []
        for i in range(n - 1):
            for item in close_list:
                for j in range(item % 10 + 1, 0, -1):
                    open_list.append(item * 10 + j)
            close_list = open_list
            open_list = []
        return close_list

    def generateParenthesisTreeFromX(self, x: int) -> dict:
        d = defaultdict(list)
        for c in str(x):
            c = int(c)
            if c == 1:
                node = Parenthesis()
                d[c].append(node)
                continue
            if d[c - 1]:
                parent = d[c - 1][-1]
                node = Parenthesis()
                parent.next.append(node)
                d[c].append(node)
        return d

    def generateParenthesisFromX(self, x: int) -> str:
        d = self.generateParenthesisTreeFromX(x)
        return ''.join([str(x) for x in d[1]])

    def generateParenthesis(self, n: int) -> list:
        result = []
        x_list = self.generateDigitals(n)
        for x in x_list:
            result.append(self.generateParenthesisFromX(x))
        return result

```