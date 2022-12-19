  func rob(rt *TreeNode) int {
	lv1,_:=q(rt)
	return  lv1
}
//和打家劫舍一毛一样  把一层看作之前的一个数就行 偷了a[2] 就不能偷a[1]和   a[3]
//		   1		a[3]
//		2   3		a[2]
//	4   5   6  7	a[1]
//
func q(rt *TreeNode)(int,int){

	if rt==nil{	return 0,0}
	v1,a1:=q(rt.Left)
	v2,a2:=q(rt.Right) //后续遍历 从最后一层开始
	lv1:=max(rt.Val+a1+a2,v1+v2)//假设这里是a[3] 最多偷 max(a[2],a[1]+a[3])
	lv2:=v1+v2	
	return lv1 ,lv2

}



 func max(a,b	int)int{
	if a>b {	return a}
	return b
 }