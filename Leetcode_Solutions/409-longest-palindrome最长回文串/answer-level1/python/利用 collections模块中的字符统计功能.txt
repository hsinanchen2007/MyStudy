### 解题思路
collections模块的Counter函数可以统计字符出现次数，
而此题的关键就是统计字符出现次数大于1的个数，因为出现次数大于1才能出现回文情况
分为下面几种情况flag_1表示x出现次数大于1的奇数次标记，flag为有没有字符x出现一次的标记
1.考虑到同一字符x出现奇数次(大于1),则flag_1=1表示在所有字符都大于1的情况下有单一字符总回文长度需要加1


### 代码

```python3
from collections import Counter
class Solution:
    def longestPalindrome(self, s: str) -> int:
        a = Counter(s)
        #print(a)
        length = 0
        flag = 0
        flag_1 =0
        for item in a:

            if a[item] > 1 :
                if a[item] %2 ==0:
                    length += a[item]
                else:
                    flag_1 =1
                    length +=a[item]-1
            else:
                flag =1
        if flag ==0:
            return(flag_1+length)
        else:
            return(length+1) 
```