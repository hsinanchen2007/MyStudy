### 解题思路
大致同主站习题 [443. 压缩字符串](https://leetcode-cn.com/problems/string-compression/)
稍微有点不一样，这里需要补1， 而那题需要原地返回。
``` python3
for i in range(5):#python3似乎修复了此问题，for 中的i比较特殊，i永远取0,1,.. 5,不会跳过数字，也不会到 6
    i += 1     #  这里的 i 是每次从for 循环中的 i 读一下值而已
    print(i)
# 1,2,3,4,5,6
```


### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if len(S) <= 2:
            return S
        res = ""
        tmp, n = S[0], 1
        # for i in range(1, len(S)):  ## 这样写代码不会有 BUG?? 
        ##会导致重复循环，即使下面i 很大了，到了for 循环又变小了，会出错
        
        i = 1
        while i<len(S):
            if S[i]==tmp:
                while i<len(S) and S[i] == tmp:
                    i += 1
                    n += 1
            else:
                res = res + tmp +str(n)
                tmp = S[i]
                n = 1
                i += 1
        ## 延后处理
        res = res + tmp + str(n)
        if len(res) < len(S):
            return res
        else:
            return S

```