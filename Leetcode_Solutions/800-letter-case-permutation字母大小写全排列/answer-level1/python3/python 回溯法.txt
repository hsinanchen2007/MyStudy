### 解题思路
进行简单的回溯就好，如果是字母，进行大小写回溯，不是字母的话，在递归中只传入字符本身

### 代码

```python3
class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        ans=[]
        def helper(s,pre):
            if not s:
                ans.append("".join(pre))
                return
            if s[0].isalpha():
                helper(s[1:],pre+[s[0].upper()])
                helper(s[1:],pre+[s[0].lower()])
            else:
                 helper(s[1:],pre+[s[0]])
        helper(S,[])
        print(ans)
        return ans

```