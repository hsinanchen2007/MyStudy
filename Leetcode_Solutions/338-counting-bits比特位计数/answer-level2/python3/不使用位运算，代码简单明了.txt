# 简单的思路

N位的情况不就是在1，2，3，...N-1位的所有前面，最高位加个1这么简单吗？

```python []

class Solution:
    def countBits(self, num: int) -> List[int]:

        if num ==0:
            return [0]
        if num ==1:
            return [0,1]
        temp = [0,1]
        while((num-len(temp))>=0):
            temp+=[(1+x) for x in temp]
        return temp[:(num+1)]

```
不分情况，也满足一趟循环的要求。
