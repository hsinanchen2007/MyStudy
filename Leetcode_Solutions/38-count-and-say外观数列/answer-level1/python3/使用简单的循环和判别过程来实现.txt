### 解题思路
每一序列里的内容都是统计前一序列中依次出现的重复元素与其个数；所以使用简单的循环和判别，即可实现这一函数。


### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        s="1"
        k=1
        while k<=n-1:
            s1=""
            m=i=j=0
            while i <len(s):
                if s[i]==s[j]:
                    m+=1
                    i=i+1
                else:
                    s1=s1+str(m)+s[i-1]
                    j=i
                    m=0 
            s1=s1+str(m)+s[i-1] 
            s=s1
            k=k+1
        return s

```