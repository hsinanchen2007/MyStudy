### 代码

```python3
class Solution(object):
    def restoreIpAddresses(self, s):
        ret = []
        def dfs(p,index,level,res):
            if level==5 or index>=len(s):
                if level==5 and index==len(s):
                    ret.append('.'.join(res))
                return
            for i in range(1,4):
                x=s[index:index+i]
                if int(x)<256 and  not str(x).startswith('0') or x=='0':
                    res.append(x)
                    dfs(p,index+i,level+1,res)
                    res.pop()
        res = []
        dfs("25525511135",0,1,res)
        return ret

```