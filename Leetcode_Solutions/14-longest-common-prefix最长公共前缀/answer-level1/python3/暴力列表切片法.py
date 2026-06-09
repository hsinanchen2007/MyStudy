### 解题思路
找到最短字符长度N，循环n次，用集合长度是否为1判断前缀是否相同

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs)==0:
            return ''
        if len(strs)==1:
            return strs[0]
        else:
            n =min([len(i) for i in strs])
            str=''
            for i in range(1,n+1):
                flag=len(set([x[0:i] for x in strs]))
                if flag==1:
                    str=strs[0][0:i]
            return str
            


```