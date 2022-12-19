### 解题思路
执行用时 :
32 ms
, 在所有 Python3 提交中击败了
87.85%
的用户
内存消耗 :
13.2 MB
, 在所有 Python3 提交中击败了
48.36%
的用户
### 代码

```python3
class Solution:
    def toGoatLatin( self,S: str) -> str:
        s_list=S.split(" ")
        i=1
        res_list=[]
        for each_word in s_list:
            if each_word[0] in ["a","e","i","o","u","A","E","I","O","U"]:
                each_word+="ma"
            else:
                char_first=each_word[0]
                each_word=each_word[1:]
                each_word+=char_first
                each_word += "ma"
            for ii in range(0, i):
                each_word += "a"
            i += 1
            res_list.append(each_word)
        res=""
        for e in res_list:
            res+=(e+" ")
        return res[:-1]

```