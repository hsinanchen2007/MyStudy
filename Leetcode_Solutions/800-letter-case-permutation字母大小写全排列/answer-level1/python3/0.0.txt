### 解题思路
也就是一个遍历的思想，遇到字母了就把它反转后加入进去

### 代码

```python3
class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:

        def get_change_char(S):
            ans=[S]
            for idx,i in enumerate(S):
                now_str=S[:idx]
                #print(now_str,idx)
                if i.isalpha():
                    tmp=S[idx].swapcase()
                    now_str=now_str+tmp+S[idx+1:]
                    for x in ans:
                        print(x)
                        ans=ans +[x[:idx]+tmp+x[idx+1:]] 
            return ans
        return (get_change_char(S))
```