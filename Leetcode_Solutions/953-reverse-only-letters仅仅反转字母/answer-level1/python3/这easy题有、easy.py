### 解题思路
执行用时 :
36 ms
, 在所有 Python3 提交中击败了
69.42%
的用户
内存消耗 :
13.2 MB
, 在所有 Python3 提交中击败了
25.20%
的用户
### 代码

```python3
class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        other_char={}
        alpah=[]
        for i in range(0,len(S)):
            if not S[i].isalpha():
                other_char[i]=S[i]
            else:
                alpah.append(S[i])
        alpah1=alpah[::-1]
        for each_index,each_char in other_char.items():
            alpah1.insert(each_index,each_char)
        res=""
        for s in alpah1:
            res+=s
        return res

```