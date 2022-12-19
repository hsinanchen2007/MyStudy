### 解题思路
遍历s中的字符，查找在t中第一次出现的index。注意每次遍历下一个字符时，查找的t需要从上一个index+1开始.
如果遍历可以完成，说明时True，否则False。
无论t有多大，速度都很快。
执行用时 :
40 ms, 在所有 Python3 提交中击败了83.62%的用户
### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
       
        temp = -1
        for x in s:
            temp = t.find(x, temp+1)
            if temp == -1:
                return False
        return True


```