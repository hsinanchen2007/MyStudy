思路：从小到大搜索二叉搜索树就是中序遍历 为了避免已经找到答案后的无效递归 可以使用sys.exit(1)强制终止+try:except结构来捕获异常
注意：本人菜鸡 效率不见得好 还请大家多多指教
```
from sys import exit
class Solution:
	def kthSmallest(self,root,k):
		ans=0
		count=0
		def helper(root,k):
			nonlocal ans,count
			if root:
				helper(root.left,k)
				count+=1
				if count==k:
					ans=root.val
					exit(1)
				helper(root.right,k)
		try:
			helper(root,k)
		except:
			return ans
```
