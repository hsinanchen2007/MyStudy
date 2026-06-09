当我看到这个题，我首先想的就是ccollections库中的Counter，将每个字母出现的次数先统计出来。
接下来就求小于等于次数的最大偶数之和，毕竟回文一般是要两个两个的。
接下来就有个问题，就是存在中间一个字的次数为奇数的情况，所以就得判断有无次数为奇数的字母，如果有，最后就得加1.
代码如下。
```python []
from collections import Counter
class Solution:
    def longestPalindrome(self, s: str) -> int:
        coun = Counter(s)   #用Counter函数计数，结果为字典形式
        temp,tm = 0,0
        for i in coun:
            temp += coun[i]//2*2   #求小于等于key值的最大偶数，然后相加
            if coun[i]%2 == 1:    #判断是否存在奇数key，如果有奇数key那tm为1，如果没有tm=0
                tm = 1
        return temp + tm
        

```
嘛，虽然效率不高，但思路倒是挺清晰，挺好想的。

