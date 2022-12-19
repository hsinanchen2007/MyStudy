### 解题思路
**1.Python标准库之collections**

### 代码

```python
from collections import Counter
class Solution(object):
    def countCharacters(self, words, chars):
        len_w = 0
        for w in words:
            #作用等同于创建一个字典
            ans = Counter(w)
            #取交集，若是交集之后等于ans，则证明可以
            if ans == (ans & Counter(chars)):
                len_w += len(w)
        return len_w
```
### 解题思路
2。与方法一类似，不过不借助oython本身的库
```python
class Solution(object):
    def countCharacters(self, words, chars):
        len_w = 0
        dic = {}
        for w in words:
            for i in w:
                if i not in dic:
                    dic[i] = 1
                else:
                    dic[i] += 1
            if all(c in chars and dic[c] <= chars.count(c) for c in dic):
                len_w += len(w)
            dic = {}
        return len_w
```
