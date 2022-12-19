### 解题思路
递归实现，用一个map[int][]int表示第i层的元素
![image.png](https://pic.leetcode-cn.com/6b81c3f8b768b2ead3457b6481662478d93f7970133409b9cf348599fd6708f1-image.png)


### 代码

```golang
func processSubTree(left,right *TreeNode,levelMap map[int][]int,level int){
	if left==nil&&right==nil{
		return
	}else if left!=nil&&right==nil{
		_,ok:=levelMap[level]//注意：先要判断第i层是否已经存在了元素，如果存在则append，不存在才能直接赋值！！！
		if !ok{
			levelMap[level]=[]int{left.Val}
		}else {
			levelMap[level]=append(levelMap[level],left.Val)
		}
		processSubTree(left.Left,left.Right,levelMap,level+1)
	} else if left==nil&&right!=nil{
		_,ok:=levelMap[level]
		if !ok {
			levelMap[level] = []int{right.Val}
		}else {
			levelMap[level] =append(levelMap[level],right.Val)
		}
		processSubTree(right.Left,right.Right,levelMap,level+1)
	} else if left!=nil&&right!=nil {
		_,ok:=levelMap[level]
		if !ok {
			levelMap[level] = []int{left.Val, right.Val}
		}else {
			levelMap[level] =append(levelMap[level] ,[]int{left.Val, right.Val}...)
		}
		processSubTree(left.Left,left.Right,levelMap,level+1)
		processSubTree(right.Left,right.Right,levelMap,level+1)
	}
}
func levelOrderBottom(root *TreeNode) [][]int {
	res:=make([][]int,0)
	if root==nil{
		return res
	}
	levelMap:=make(map[int][]int,0)
	levelMap[0]=[]int{root.Val}
	processSubTree(root.Left,root.Right,levelMap,1)
	levelDeep:=len(levelMap)
	for i:=levelDeep-1;i>=0;i--{
		res= append(res, levelMap[i])
	}
	return res
}
```