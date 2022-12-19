### 解题思路
这是我在leetcode上刷的第三道题目，也是比前两道简单许多的题目。依旧首先想到的是最笨的办法。看到评论中有大神用了二进制的算法，没看懂。 还是需要努力。 今晚就到这里吧，晚安，2020-4-1 23：42。

### 代码

```python3
class Solution:
    def numberOfSteps (self, num):
        times = 0
        while num > 0:
            if num%2 == 1:
                num -= 1
            else:
                num = num/2
            times +=1
        return times
```