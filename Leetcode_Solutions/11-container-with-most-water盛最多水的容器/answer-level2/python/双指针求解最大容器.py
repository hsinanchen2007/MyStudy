### 解题思路
此处撰写解题思路
这题应该是归类到简单题去，上面那个最长回文子串真TM的难   
### 代码

```python
class Solution(object):
    def maxArea(self, a):
        i = 0
        j = len(a) - 1
        temp = -1
        print(max(9, 9))
        while (i != j):
            t = min(a[i], a[j]) * (j - i)
            if t > temp:
                temp = t
            if a[i] <= a[j]:
                i += 1
            else:
                j -= 1
        return temp
        """
        :type height: List[int]
        :rtype: int
        """
```