### 解题思路
第1种是按照归并的方式，将问题规模缩小，所有字符串的公共首字符串=（part1的公共首字符串 and part2的公共首字符串）的公共首字符串
第2种是如果第一个字符都相同，那么首字符+所有字符串的剩下字符的公共首字符串为结果。


### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs):
        if len(strs)==0:
            return ""
        if len(strs)==1:
            return strs[0]
        if len(strs)==2:
            index=0
            common=""
            while True:
                if index>=len(strs[0]) or index>=len(strs[1]):
                    return common
                if strs[0][index]==strs[1][index]:
                    common+=strs[0][index]
                    index+=1
                else:
                    return common
        else:
            medium=len(strs)//2

            return self.longestCommonPrefix([self.longestCommonPrefix(strs[:medium]),self.longestCommonPrefix(strs[medium:])])

```
```python3
def longestCommonPrefix(self, strs):
    char_set=set()
    for string in strs:
        if not string:
            return ""
        char_set.add(string[0])

    if len(char_set)==1:
        rest=[]
        for string in strs:
            rest.append(string[1:])

        common=char_set.pop()
        return common+self.longestCommonPrefix(rest)
    else:
        return ""
```