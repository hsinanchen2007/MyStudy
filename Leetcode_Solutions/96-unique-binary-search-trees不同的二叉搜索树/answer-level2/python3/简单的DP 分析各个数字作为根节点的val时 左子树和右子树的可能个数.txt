思路：见标题 本人菜鸡 主要的语句都添加了注释(语死早 所以主要是举例子 希望能方便大家理解) 还请大家多多指教
```
class Solution:
	def numTrees(self,n):
		if n<=1:
			return 1
		situ=[1,1] #situ[1]表示这个搜索树有1个节点的时候存在着1种二叉搜索树 situ[0]=1主要是为了方便 可配合🚩处便于明白
		for i in range(2,n+1): #以1,2,3为例 1在根节点的时候 需要有0个节点的二叉搜索树作为左子树和2个节点的二叉搜索树作为右子树...
			tmp=0
			a,b=divmod(i,2) #为了避免重复计算 因为就像杨辉三角一样有着对称关系
			for j in range(a):
				tmp+=situ[j]*situ[i-j-1] #🚩 左子树的可能个数*右子树的可能个数
			tmp*=2
			if b: #如果是奇数个 如:1,2,3,4,5 需要单独加上3作为根节点val时可行的二叉搜索树的个数
				tmp+=situ[a]**2
			situ.append(tmp)
		return situ[-1]
```
