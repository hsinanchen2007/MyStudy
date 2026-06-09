/*
注意二维数组的坑！！！
如果getSonNode不返回[][]int
则最后的resArr不是改变后的！！！
*/

func levelOrder(root *TreeNode) [][]int {
	if root==nil{
		return nil
	}
	resArr:=make([][]int,0)
	resArr=getSonNode(root,0,resArr)
	return resArr
}
func getSonNode(node *TreeNode,level int,resArr [][]int)[][]int{
	if node==nil{
		return resArr
	}
	if len(resArr)<=level {
		resArr = append(resArr, []int{})
	}
	resArr[level]=append(resArr[level],node.Val)
	//fmt.Println(resArr)
	resArr=getSonNode(node.Left,level+1,resArr)
	resArr=getSonNode(node.Right,level+1,resArr)
	return resArr
}