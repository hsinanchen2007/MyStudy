**思路**:每一个节点和其左右子树的取舍 递归中的当前节点和其左右子树可以看成是一个子树 递归函数的两个返回值一个是该子树偷根节点时能偷到的最大金额 一个是不偷根节点时能偷到的最大金额
**注意**:本人菜鸡 主要的语句都添加了注释 还请大家多多指教
```python []
class Solution:
	def rob(self,root):
		def helper(root):
			if not root: #空的节点 注意返回值应该是两个0
				return [0]*2
			le_0,le_1=helper(root.left) #le_0表示左子树不含左子树根节点能偷到的最大值 le_1表示左子树含左子树根节点能偷到的最大值
			ri_0,ri_1=helper(root.right) #同理 见上面
			le_max=max(le_1+ri_1,le_0+ri_1,le_1+ri_0,le_0+ri_0) #curr_0的四种可能中选出最大的一个 <- 最后一个很容易被忽略 我开始的时候就没注意到 /(ㄒoㄒ)/~~ 或者直接写成le_max=max(le_0,le_1)+max(ri_0,ri_1) <- AC后看了大佬的题解才意识到
			return [le_max,le_0+ri_0+root.val]
		return max(helper(root))
```
```golang []
import "math"
func rob(root *TreeNode) int {
	return int(math.Max(helper(root))) //注意最后要强制类型转换
}
func helper(root *TreeNode) (float64,float64) { //方便起见 Max的两个参数都得是float64类型的
	if root==nil { //空节点 俩返回值都是0
		return 0,0
	} else {
		le_0,le_1:=helper(root.Left) //左子树
		ri_0,ri_1:=helper(root.Right) //右子树
		max:=math.Max(le_0,le_1)+math.Max(ri_0,ri_1) //左子树的最大偷取值+右子树的最大偷取值
		//也许max(le_0+ri_0,le_0+ri_1,le_1+ri_0,le_1+ri_1)更好理解
		return max,le_0+ri_0+float64(root.Val) //第二个返回值:因为要偷当前子树的根节点 所以根据题目要求只能这样
	}
}
```

