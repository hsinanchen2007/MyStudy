### 解题思路
1. 首先定位i为可取字符串的位置
2. 随后保证字符串的长度在min-max之间
3. 每次加入一个字符，如果加入字符之后不同字符的数目超过maxletter，则break，否则加入字典

### 代码

```
class Solution:
    def maxFreq(self, s, maxLetters, minSize, maxSize):
        length = len(s)
        res = {}
        if(length<minSize or minSize>maxSize):
            return 0
        for i in range(length-minSize+1):
            tmp = s[i:i+minSize-1]
            num = len(set(tmp))
            if(num>maxLetters):
                continue
            for j in range(minSize-1, maxSize):
                if(i+j>=length):
                    break
                num = num+1 if(s[i+j] not in tmp) else num
                if(num>maxLetters):
                    break
                else:
                    tmp+=s[i+j]
                    if(tmp in res):
                        res[tmp]+=1
                    else:
                        res[tmp] = 1
        if(len(res) == 0):
            return 0
        return sorted(res.items(), key=lambda x:x[1], reverse=True)[0][1]
```