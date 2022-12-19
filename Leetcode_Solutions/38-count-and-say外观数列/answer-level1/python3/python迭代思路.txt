### 解题思路
此处撰写解题思路，用一个while循环判断公共字符串长度

### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        st = []
        st.append('1')
        for i in range(n-1):
             j=0 
             ns=[]
             while j<len(st):
                 k=j
                 while k<len(st) and st[k]==st[j]:
                     k+=1
                 ns.append(str(k-j))
                 ns.append(str(st[j]))
                 j=k-1
                 j+=1
             st=ns
        return ''.join(st)
```