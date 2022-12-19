### 解题思路
![5377.PNG](https://pic.leetcode-cn.com/6ced240772d4523b2a8d57c1abbee104e75f839134da22c0c621e3e9ed4ba072-5377.PNG)

### 代码

```python3
class Solution:
    def numSteps(self, s: str) -> int:
        jige=0
        s=int(s,2)
        while s!=1:
            if s%2==0:
                s=s//2
            else:
                s+=1
            jige=jige+1
        return jige
```