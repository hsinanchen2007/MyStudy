/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
  var ma map[int]int
  func pathSum(root *TreeNode, sum int) int {
	ma=make(map[int]int,500)
	 
	 count:=0
	 ww:=0
	 ma[0]=1
	 q(root,sum,&ww,&count)
	 return count
 }
 func q(rt *TreeNode, sum int,ww *int,count *int){
 
	 if rt==nil{	return}
	
	 *ww +=rt.Val//区间连续和
	 oo:=*ww
	 if _,ok:=ma[*ww-sum];ok{	*count +=ma[*ww-sum]}
	 ma[*ww]++   
	 
	 q(rt.Left,sum,ww,count)
	 q(rt.Right,sum,ww,count)
	 ma[oo]--       //回溯
	 *ww-=rt.Val
 }