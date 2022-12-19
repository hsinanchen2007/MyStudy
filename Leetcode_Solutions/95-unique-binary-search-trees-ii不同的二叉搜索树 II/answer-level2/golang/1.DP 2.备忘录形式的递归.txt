**思路**:可见官方题解 或者看下文的注释(本人菜鸡 基本主要语句都给了注释 代码仅供参考 还请各位多多指教)

# 一.DP
```python []
from functools import reduce
from operator import add
def leetcode_95(n):
	if n:
		dp={0:dict.fromkeys(range(1,n+2),[None])} #外层的键表示当前的树由多少个数字组成 内层的键表示root的val
		for i in range(1,n+1): #表示当前创建的树由i个数字组成
			dp[i]=dict()
			for j in range(1,n+2-i): #表示左端起始的索引
				dp[i][j]=list()
				for dis in range(i): #当前子树的根节点的左子树由dis个数字构成
					for le in dp[dis][j]: #分别得到所有可能的左右子树
						for ri in dp[i-dis-1][j+dis+1]:
							new=TreeNode(dis+j) #当前的子树的根节点
							new.left,new.right=le,ri #填充
							dp[i][j].append(new)
		return reduce(add,dp[n].values()) #合并所有的结果并返回
	return [] #n==0比较特殊 需要单独处理
```
```golang []
/*golang的都是在py3后面写的 但这边还是尽量保持细节和py3的DP一致 不做什么改进了*/
func generateTrees(n int) (ans []*TreeNode) {
	if n!=0 {
		dp:=map[int]map[int][]*TreeNode{0:make(map[int][]*TreeNode)}
		for i,t:=1,make([]*TreeNode,1);i<=n+1;i++ {
			dp[0][i]=t
		}
		for i:=1;i<n+1;i++ { //表示该轮要创建的树由i个数字构成
			dp[i]=make(map[int][]*TreeNode)
			for j:=1;j<n+2-i;j++ { //这个算是起部分子树的起始索引
				dp[i][j]=make([]*TreeNode,0)
				for dis:=0;dis<i;dis++ { //
					for _,x:=range dp[dis][j] { //可能的左子树们
						for _,y:=range dp[i-dis-1][j+dis+1] { //可能的右子树们
							dp[i][j]=append(dp[i][j],&TreeNode{j+dis,x,y})
						}
					}
				}
			}
		}
		for i:=1;i<=n;i++ { //收集结果
			ans=append(ans,dp[n][i]...)
		}
	}
	return //n==0是特殊情况 需要区别处理
}
```

# 二.递归
注:有个小细节稍微和上面有些不同 就是分当前子树的根节点的左右子树时上面用的是各部分的左边界idx和len 这边用的是各部分的左边界和右边界的idx(前者是一开始AC的做法 后者借鉴了大佬们的题解进行了改进)
```python []
def leetcode_95(n):
	memo=dict.fromkeys(zip(range(1,n+2),range(n+1)),[None]) #备忘录 也可以直接给一个dict但是helper里面就要判断if le>ri:了
	def helper(le,ri): #左右端点的idx
		if (le,ri) not in memo:
			ans=[]
			for i in range(le,ri+1): #i表示的是要创建的子树的根节点的值
				for x in memo.get((le,i-1),helper(le,i-1)):
					for y in memo.get((i+1,ri),helper(i+1,ri)):
						new=TreeNode(i)
						new.left,new.right=x,y #填充当前根节点的左右子树
						ans.append(new) #加入到ans里面去
			memo[(le,ri)]=ans
		return memo[(le,ri)]
	return helper(1,n) if n else [] #n==0是一种特殊情况需要分开来处理的
```
```golang []
func generateTrees(n int) (ans []*TreeNode) {
	if n!=0 {
		memo:=make(map[[2]int][]*TreeNode) //⭐数组可以作为map的键 但是切片是不可以作为键的
		for i,t:=1,make([]*TreeNode,1);i<=n+1;i++ { //备忘录的预先处理 也可以没有这一段但是没有的话就需要在helper里面由if le>ri {}一个条件判断
			memo[[2]int{i,i-1}]=t
		}
		var helper func(int,int) []*TreeNode //需要一个辅助的递归函数
		var get func(int,int) []*TreeNode //相当于实现了python3的dict.get() 用起来比较舒服
		helper=func (le,ri int) []*TreeNode {
			locate,ans:=[2]int{le,ri},[]*TreeNode{} //ans收集子结果集
			if _,ok:=memo[locate];!ok { //没找到的话就需要使用
				for i:=le;i<=ri;i++ { //i表示的是当前要建立的子树tree的根节点的Val
					for _,x:=range get(le,i-1) { //tree根节点的可能的左子树们
						for _,y:=range get(i+1,ri) { //tree根节点的可能的右子树们
							ans=append(ans,&TreeNode{i,x,y})
						}
					}
				}
				memo[locate]=ans
			}
			return memo[locate]
		}
		get=func (le,ri int) []*TreeNode { //备忘录里面有的话就直接从memo取 否则helper()得到并记录在备忘录中
			if v,ok:=memo[[2]int{le,ri}];!ok {
				return helper(le,ri)
			} else {
				return v
			}
		}
		return helper(1,n)
	}
	return //n==0是一种特殊的情况 徐娅萍特别的处理
}
```

