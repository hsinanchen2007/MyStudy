### 解题思路
首先将字符串存入哈希表，再计算每个字符奇数个的个数，如果奇数个数大于2个，就判定False

### 代码

```python
class Solution(object):
    def canPermutePalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        #用哈希表
        h = {}
        k = 0
        for i in s:
            if i not in h.keys():
                h[i] = 0
            else:
                h[i] += 1
        #print(h)
        for j in h.values():
            #print(j)
            if (j % 2) == 0:
                k += 1
        #print(k)
        if k > 1:
            return False
        else:
            return True
```