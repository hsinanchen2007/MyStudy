### 解题思路
要进行试错的组合ip，所以采用回溯法，ip地址的组成有许多限制条件：总共只有4段；每段的数字大小在0~255闭区间里。有这些限制条件，可以用来剪枝。

### 代码

```python3
class Solution:
    def restoreIpAddresses(self, s: str):
        def backtrack(start,depth,ip):
            if depth==4 and start==len(s):
                res.append('.'.join(ip))
                return
            elif depth>=4:
                return
            for i in range(start,min(start+3,len(s))):
                # 待添加的ip部分
                tmp = s[start:i+1]
                if i-start+1>1 and tmp[0]=='0': #若长度大于1位，但首位为0
                    break
                if int(tmp)<256: #ip地址每一段都要小于256
                    ip.append(tmp)
                    backtrack(i+1,depth+1,ip)
                    ip.pop()
        if not s:
            return []
        res = []
        backtrack(0,0,[])
        return res
```