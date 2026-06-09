### 解题思路
没有花里胡哨的技巧
三个变量:
记录首位,计数,结果
如果相等计数+1
要么增加首位加计数
更新首位和计数重置为1
最后补上最后的首位加计数






如果相等计数+1
不等就

### 代码

```python3
class Solution:
    def compressString(self, s: str) -> str:
        if not s:
            return ''
        cur = s[0]
        cnt = 1
        ans = ''
        for val in s[1:]:
            if val == cur:
                cnt+=1
            else:
                ans += cur+str(cnt)
                cur = val
                cnt =1
        ans += cur+str(cnt)
        return ans if len(ans)< len(s) else s

```