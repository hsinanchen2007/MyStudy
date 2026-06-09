### 解题思路
执行用时 :40 ms, 在所有 Python3 提交中击败了44.77%的用户
### 代码

```python3
class Solution:
 def isValid(self,s:str,t=0)->bool:
  while len(s)!=t:s,t=s.replace('()','').replace('[]','').replace('{}',''),len(s)
  return len(s)==0
```