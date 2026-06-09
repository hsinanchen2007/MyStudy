### 解题思路1
利用zip函数进行压缩

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        s = ""
        for i in zip(*strs):
            if len(set(i)) == 1:
                s += i[0]
            else:
                break           
        return s
```
### 解题思路2
水平扫描
```
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        s=''
        if not strs:
            return ''
        for i,letter in enumerate(strs[0]):
            num=0
            for j in strs[1:]:
                if len(j)>=i+1:
                    if letter==j[i]:
                        num+=1
                    else:
                        break
                else:
                    break
            if num==len(strs)-1:
                s+=letter
            else:
                break
        return s
```
