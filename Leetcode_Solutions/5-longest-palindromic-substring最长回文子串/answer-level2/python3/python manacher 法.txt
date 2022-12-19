### 解题思路
找了许多一般说这里有四种解法，动态规划一直不会，用Python实现了暴力法，中心拓展和manacher法，最后一个比较麻烦这里贴出来。
manacher线性的复杂度，说起来也有一点麻烦。总而言之就是在字符串首尾以及每个字符之间都加上一个其他字符，这样以后不管原来的回文串长度是奇数还是偶数，新字符串中回文串长度都将是奇数。
贴个详细连接：https://blog.csdn.net/sinat_41053216/article/details/105083200
### 代码

```python3
class Solution:
    def longestPalindrome(self, s):
        length = len(s)
        if length==0 or length==1:
            return s
        i = 1
        ts = ''.join(['#'+i for i in s])+'#'
        le = [1]
        p0 = 0
        p = 0
        rescenter = 0
        resmlen = 1
        while i<=length*2:
            if i<=p:
                j = 2*p0-i
                if le[j] < p-i:
                    le.append(le[j])
                else:
                    count = p-i+1
                    r = p+1
                    while r<=len(ts)-1 and ts[r]==ts[2*i-r]:
                        count += 1
                        r +=1
                    le.append(count)
                    p0 = i
                    p = r-1
            else:
                count = 1
                r = i+1
                while r<=len(ts)-1 and ts[r] == ts[2*i-r]:
                    count += 1
                    r += 1
                le.append(count)
                p0 = i
                p = r-1
            if le[i]>resmlen:
                rescenter = i
                resmlen = le[i]
            i += 1
        start = (rescenter-(resmlen-1))//2
        end = start + (resmlen-1)
        return s[start:end]
```