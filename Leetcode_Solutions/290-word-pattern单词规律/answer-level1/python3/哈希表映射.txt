### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        pat=[]
        hash_pat={}
        k=0
        for i in range(len(pattern)):
            if pattern[i] not in hash_pat.keys():
                k+=1
                hash_pat[pattern[i]]=k
                pat.append(k)
            else:
                pat.append(hash_pat[pattern[i]])

        list_str=[]
        sub=''
        for j in range(len(str)):
            if str[j]!=' ':
                sub+=str[j]
            else:
                list_str.append(sub)
                sub=''
        list_str.append(sub)
        pat2=[]
        hash_pat2={}
        m=0
        for i in range(len(list_str)):
            if list_str[i] not in hash_pat2.keys():
                m+=1
                hash_pat2[list_str[i]]=m
                pat2.append(m)
            else:
                pat2.append(hash_pat2[list_str[i]])
                
        if pat==pat2:
            return True
        else:
            return False


        


```