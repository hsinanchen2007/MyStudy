
   遍历S中每个字符，分成和前一个相同或不相同两种情况，然后还有一种当前字符为最后字符的处理

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        l=len(S)
        if l<1:
            return ''
        else:

            i=1
            st=[S[0]]
            a=S[0]
            l_s=1
            while i<l:
                if a!=S[i]:
                    st.append(str(l_s))
                    st.append(S[i])
                    l_s=1
                    a=S[i]
                    if i==l-1:
                        st.append(str(l_s)) 
                else:
                    l_s+=1
                    if i==l-1:
                        st.append(str(l_s))    
                i+=1
            st_str=''.join(st)
            if len(st_str)>=len(S):
                return S
            else:
                return st_str
```
![image.png](https://pic.leetcode-cn.com/f7e0530f32e5e8acf130085b342102e2882bcdb98b293abc6aa034c163b53b81-image.png)
