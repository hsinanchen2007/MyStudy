### 解题思路
。。我估计完全可以用字典来做吧

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        s_hat = [_ for _  in S]
        size  = len(s_hat)
        if size == 0:
            return ''
        s_rs = s_hat.pop(0)
        size -= 1
        cnt = 1
        if size == 0:
            s_rs = s_rs +'1'
        # loop
        while size >= 1:
            tmp = s_hat.pop(0)
            if tmp == s_rs[-1]:
                cnt +=1
                if size == 1:
                    s_rs = s_rs + str(cnt)
                size -= 1
            else :
                s_rs = s_rs + str(cnt)
                cnt = 1
                s_rs = s_rs + str(tmp)
                if size == 1:
                    s_rs = s_rs + str(cnt)
                size -= 1
        return s_rs if (len(s_rs)<len(S)) else S
        
```