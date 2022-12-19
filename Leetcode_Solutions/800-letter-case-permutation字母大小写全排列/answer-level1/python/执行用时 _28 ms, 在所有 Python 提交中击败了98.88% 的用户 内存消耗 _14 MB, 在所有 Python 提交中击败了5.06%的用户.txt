### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def letterCasePermutation(self, S):
        # 回溯
        len_s=len(S)
        res=[]

        def traceback(n,path):
            if n==len_s:
                res.append(path)
                return

            if S[n].isdigit():
                    traceback(n+1,path+S[n])
            else:
                traceback(n+1,path+S[n].lower())
                traceback(n+1,path+S[n].upper())
                
        traceback(0,'')
        return res

        """
        :type S: str
        :rtype: List[str]
        """
```