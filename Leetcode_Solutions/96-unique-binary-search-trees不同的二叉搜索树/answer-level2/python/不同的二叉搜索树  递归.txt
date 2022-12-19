### 解题思路
学习官方题解

### 代码

```python
class Solution(object):
    def numTrees(self, n):
       #卡特兰数
        if not n or n == 1:
           return 1
        G = [0]*(n+1) #G(n)代表长度n时的二叉树数量，仅与序列长度有关
        #F(i,n)表示以i位根时1<=i<=n时的二叉树数量 F(i,n)=G(i-1)*G(n-i) 
        #序列长的二叉树数量的笛卡尔乘积
        #G(n) = sum(F(i,n)) i:1~n
        G[0] = 1
        G[1] = 1
        for i in range(2,n+1):
            for j in range(1,i+1):
                G[i] += G[j-1] * G[i-j]
        return G[n]
```