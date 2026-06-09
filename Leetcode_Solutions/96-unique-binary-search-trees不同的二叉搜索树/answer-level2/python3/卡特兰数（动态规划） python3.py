# 题解
典型的卡特兰数问题，可使用动态规划来解决。
设$n$个结点的二叉搜索树的种类为$G(n)$，$f(i)$表示以$i$为根节点的二叉搜索树的种数。可得：
$G(n)=f(1)+f(2)+\cdots+f(n)$。
又因：
$f(i)=G(i-1)*G(n-i)$，表示以$i$为根节点，其左子树的种类加上其右子树的种类。
可推得：
$$G(n)=G(0)*G(n-1)+G(1)*G(n-2)+\cdots+G(n-1)*G(0)=$$
即：
$$
G(n)=\sum_{i=0}^{n-1} G(i) G(n-i-1)
$$
## 动态规划

 1. 初始化$dp=[0,\cdots,0]$，长度为$n+1$，保存$0,\cdots,n$的卡特兰数。初始化$dp[0]=1,dp[1]=1$，表示没有节点和只有一个节点的二叉搜索树的种类。
 2. 遍历$dp$数组，$i$遍历区间$[2,n+1)$：
 	+ 计算卡特兰数，$j$遍历区间$[0,i)$
 		+ 由卡特兰数公式：$dp[i]+=dp[j]*dp[i-j-1]$
 
 3. 返回$dp[n]$

	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

### 复杂度分析
 - 时间复杂度：$O(n^{2})$
 - 空间复杂度：$O(n)$

### Python
```python
class Solution:
    def numTrees(self, n: int) -> int:
        if(n==0):
            return 0
        dp=[0]*(n+1)
        dp[0]=1
        dp[1]=1
        for i in range(2,n+1):
            for j in range(i):
                dp[i]+=dp[j]*dp[i-j-1]
        return dp[-1]
```