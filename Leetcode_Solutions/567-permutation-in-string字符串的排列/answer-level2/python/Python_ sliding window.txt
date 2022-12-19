### 解题思路
此题与[76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/)相似，不过相对简单的地方是窗口大小是固定的。移动窗口的时候左右同时移动。

由于比较的是字符串的组合，那么相对顺序不重要，只要每个字符的字数相同即可。这里可以用字典存贮字符的个数。当移动窗口的时候，一个方法是重新建立字典，另一个方法是根据移出移进的字符相应的更新字典。后者的时间复杂度是常数，而前者则是与字符串长度成线性关系。
### 代码

```python
import collections 
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        m, n = len(s1), len(s2)
        dic1 = collections.Counter(s1)
        i, j = 0, m-1
        dic2 = {}
        for c in s2[i:j+1]:
            if c in dic1:
                dic2[c] = dic2.get(c, 0) + 1
        def is_valid(dic2):
            for k in dic1:
                if dic2.get(k, 0) != dic1[k]:
                    return False
            return True
        while j < n:
            if is_valid(dic2): return True
            else:
                if s2[i] in dic2: dic2[s2[i]] +=-1
                i +=1
                j +=1
                if j < n and s2[j] in dic1: dic2[s2[j]] = dic2.get(s2[j], 0) + 1
        return False 



```