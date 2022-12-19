### 解题思路
不同之处：
初始化时从第一排开始连续的星号都是全排true
遇到星号左上左边上边有true就是true
其他都一样
没有优化，我去看看大佬们的解法。。。
其中一个例子的表，复习用：
![image.png](https://pic.leetcode-cn.com/a1adc6067781249b6a9e69596e1e51013eeeab95c805cb9b9e44c1bcfbe3cdbd-image.png)



### 代码

```python
class Solution(object):
    def isMatch(self, s, p):
        count={}
        count[(0,0)]=True
        for i in range(len(s)):
            count[(0,i+1)]=False
        i,index=0,0
        while i < len(p):
            if i==0 and p[i]=='*':
                while i< len(p) and p[i]=='*':
                    count[(i+1,0)]=True
                    for j in range(len(s)):
                        count[(i+1,j+1)]=True
                        index=i+1
                    i+=1
            count[(i + 1, 0)] = False
            i+=1
        if index==len(p): return count[(len(p),len(s))]
        for i in range(len(s)):
            for j in range(index,len(p)):
                if p[j]==s[i] or p[j]=='?':
                    count[(j+1,i+1)]=count[(j,i)]
                elif p[j]=='*':
                    count[(j + 1, i + 1)] = count[(j, i + 1)] or count[(j, i)] or count[(j+1,i)]
                else:
                    count[(j+1, i+1)] =False
        return count[(len(p),len(s))]

```