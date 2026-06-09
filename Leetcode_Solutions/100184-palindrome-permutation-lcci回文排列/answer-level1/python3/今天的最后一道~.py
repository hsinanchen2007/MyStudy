### 解题思路
这道题完全没啥疑问，用Counter然后转换成字典，接着利用value的迭代器遍历一边，前面几次错误因为没发现最后面有个冒号= =


### 代码

```python3
import collections
class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        a = dict(collections.Counter(s))
        b = 0
        for value in a.values():
            if value %2 == 1:
                b += 1
        return True if(b == 1 or b==0) else False
```

### 今日小结
今天做了五道最简单最基础的python题目~不得不说今天收获很大~实名表扬Leecode~重点在可以写解法啊啊啊！！！之前在Codewars上就感觉没有这个平台这么方便233~大概是我不太会用那个平台吧~