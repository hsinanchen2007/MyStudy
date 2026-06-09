### 解题思路
濒临超时的解法，python not in 真的很慢啊啊啊啊

### 代码

```python3
class Solution:
    def permutation(self, s: str) -> List[str]:
        def help(s,length,path,visit,index):
            if length==len(s):
                visit.append(path[:])
                return
            for i in range(len(s)):
                if s[i] not in path or (i not in index):
                    length+=1
                    index.append(i)
                    help(s,length,path+s[i],visit,index)
                    length-=1
                    index.pop()
        visit=[]
        index=[]
        help(s,0,'',visit,index)
        return list(set(visit))    
```

![image.png](https://pic.leetcode-cn.com/fe070440aa8704d6d4c6f0f54bb963482a936998ee07e42a45fda688ed215841-image.png)
