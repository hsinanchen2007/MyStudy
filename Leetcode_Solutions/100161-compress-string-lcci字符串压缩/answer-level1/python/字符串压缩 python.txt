我们只需要一个新数组将标记好的存进去即可。
遍历一遍，O(N)
存储空间较小O(1)
```python []
class Solution:
    def compressString(self, S: str) -> str:
        i = 1
        count = 1
        pipixia = ''
        if not S :
            return S
        ch = S[0]
        while i < len(S)  :
            if S[i] == ch and i < len(S):
                count = count + 1
            else :
                pipixia += ch + str(count)
                ch = S[i]
                count = 1
            i = i + 1
        pipixia += ch + str(count)
        return pipixia if len(pipixia) < len(S) else S
```
迷惑的是速度很玄学，道理上来说不应该存在比O(N)小的情况了，但是还是玄学击败33%，45%
算了不管他，水完签到题了
