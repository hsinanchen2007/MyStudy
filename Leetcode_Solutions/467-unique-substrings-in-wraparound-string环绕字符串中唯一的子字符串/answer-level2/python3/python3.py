### 解题思路
套路题，创建以每个字母为结尾的列表，返回最后的总和就可以了
我们记录每个字母为结尾的列表时，只记录最长的那个，因为最长的以它为结尾的字符串必然包含了较短的以它本身为结尾的字符串的所有字串
不需要重复计数

### 代码

```
class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        if not p:
            return 0
        hashmap=[0]*26
        hashmap[ord(p[0])-ord("a")]=1
        prelen=1
        for i in range(1,len(p)):
            gap=ord(p[i])-ord(p[i-1])
            if gap==1 or gap==-25:
                prelen+=1
            else:
                prelen=1
            hashmap[ord(p[i])-ord("a")]=max(hashmap[ord(p[i])-ord("a")],prelen)
        return sum(hashmap)


```