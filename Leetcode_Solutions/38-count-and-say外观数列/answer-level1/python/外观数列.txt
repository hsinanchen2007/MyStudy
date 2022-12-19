### 解题思路
此处撰写解题思路
利用python3中iterstools类可以方便解此题。此题主要是解析n-1的编码形式，比如n-1处有（111），在n处的编码就是31， itertolls.groupby方法能够查找相邻元素的个数，并输出该元素和该元素个数。刚好满足此题要求。
### 代码

```python
import itertools
class Solution(object):
    def countAndSay(self, n):
        if n == 1:
            return str(1)
        if n >= 2 and n <= 30:
            lis = '1'
            lis2 = str()
            for i in range(n-1):
                for key, group in itertools.groupby(lis):
                    lis2 = lis2 + str(len(list(group))) + key
                
                lis, lis2 = lis2, '' 
                

            return lis
```