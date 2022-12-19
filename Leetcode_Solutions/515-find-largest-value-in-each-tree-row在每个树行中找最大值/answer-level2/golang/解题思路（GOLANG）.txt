# 例如: 
          1
         / \
        3   2

    我们可以利用数组来协助解决问题，首先我们定义一个关于TreeNode的数组，其中nil为层与层之间的标识符，同时在定义一个int类型的变量depath来表示当前二叉树的层数
```
array := []*TreeNode{root,nil}
depath := -1
```
    其次遍历array数组，如果当array[i]不为nil时，把当前节点的左右节点(也就是第i+1层的节点)添加当array数组中，当array[i]为nil时，由于第i+1层的节点已经全部添加到array中了，那么我们就在array的末尾加上nil(即加上第i+1层与第i+2层的标识符)，同时将depath变量改成第i+1层。接下来就可以选出当前层的最大值Max。然后把Max加到最终数组中
```
for {
		if array[depath+1] == nil {
			break
		}
		max := array[depath+1].Val
		for i := depath+1 ; i < len(array) ; i++ {
			fmt.Println(depath,len(array)) //一个fmt提交上去用时+2ms................
			if array[i] == nil { //root的左右节点先加进array,在遇到第i层的分隔符，当第i+1层的节点都加进来以后再加上第i+1层的分隔符
			    array = append(array, nil)
				depath = i //换层也就是换index
				fmt.Println(depath)
				break
			}
			if array[i].Left != nil{
				array = append(array, array[i].Left)
			}
			if array[i].Right != nil{
				array = append(array, array[i].Right)
			}
			if array[i].Val > max{
				max = array[i].Val
			}
		}
		ret = append(ret, max)
	}
```

![1583493019(1).jpg](https://pic.leetcode-cn.com/30f028eb3d8cfd56d5f3e50c4105d76722a09981f64f1b5c4ca065d21ad977f2-1583493019\(1\).jpg)

# 代码
```
func largestValues(root *TreeNode) []int {
	ret := []int{}
	if root == nil{
		return ret
	}
	array := []*TreeNode{root,nil}
	depath := -1
	for {
		if array[depath+1] == nil {
			break
		}
		max := array[depath+1].Val
		for i := depath+1 ; i < len(array) ; i++ {
			fmt.Println(depath,len(array)) //一个fmt提交上去用时+2ms................
			if array[i] == nil { //root的左右节点先加进array,在遇到第i层的分隔符，当第i+1层的节点都加进来以后再加上第i+1层的分隔符
			    array = append(array, nil)
				depath = i //换层也就是换index
				fmt.Println(depath)
				break
			}
			if array[i].Left != nil{
				array = append(array, array[i].Left)
			}
			if array[i].Right != nil{
				array = append(array, array[i].Right)
			}
			if array[i].Val > max{
				max = array[i].Val
			}
		}
		ret = append(ret, max)
	}
	return ret
}
```
