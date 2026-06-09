### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        '''
        压缩字符串
        输入："aabcccccaaa"
        输出："a2b1c5a3"
        '''
        if S == "":
            return ""
        p = S[0]
        cout = 0
        # ans = p[0]
        ans = {}
        ans[p] = 1
        res = ""
        for i in range(len(S)):
            if S[i] == p:
                cout += 1    
                ans[S[i]] = cout
                pass
            else:
                cout = 1
                p = S[i]
                ans[p] = 1
                res += S[i-1]+str(ans[S[i-1]])
        res += S[-1] + str(ans[S[-1]])
        return res if len(res) < len(S) else S
```

遇到的困难：
本来想用一个dict解决问题的，但是发现dict只统计了全局的数量，而我们要统计的是局部数量

然后就想了一个dict来存一下，当然dict会被覆盖，但是我在覆盖之前就将其转化为结果
