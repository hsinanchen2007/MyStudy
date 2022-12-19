### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        aa=''
        if strs==[]:
            return ''
        else:
            mm=len(strs[0])
            for each in strs:
                if mm>len(each):
                    mm=len(each)
            for i in range(mm):
                ant=1
                for j in range(1,len(strs)):
                    if strs[j][i]!=strs[j-1][i]:                    
                        break
                    else:
                        ant+=1
                if ant==len(strs):
                    aa+=strs[0][i] 
                else:
                    break   
            return aa

```