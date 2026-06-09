### 解题思路
对g和s进行排序，每次找出g里最小的和s里最小的，若s不满足，则边找边删直至满足s>g. 然后把当前G和当前S从array里移除。时间复杂度为O(n+m) n为g的长度，m为s的长度
### 代码

```python
class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        g.sort()
        s.sort()
        ans = 0
        while g != [] and s != []:
            curG = g[0]
            for curS in s:
                if curG > curS:
                    s.remove(curS)
                else:
                    s.remove(curS)
                    g.remove(curG)
                    ans += 1
                    break
        return ans
```