### 解题思路
first to find the min(str)
second step you can juts compare this str[:i] with other strs to find the longst str

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if(len(strs)== 0) :
            return "";
        str1=min(strs)
        if str1=="":
            return ""
        
#print(lis)
        for i in range(len(str1)+1):
             #print(i)
             cache=str1[:i]
             #print(cache)
             for j in strs:
                 str2=j[:i]
                 #print(str2)
                 if cache not in str2:
                    return cache[:-1]
        return cache
        

```