func findDisappearedNumbers(a []int) []int {
	ans:=[]int{}
		//5  1     -1
		//0  5     5
		//列子  在a[0]找到 5  a[5]的值 改为-a[5] 下次遍历的时候看到 5 上面的1
		//变成-1 就知道 5已经找到了  其他没找到的就是没出现过的
		//【坑】 数组下标 0 到 n-1 要用 0储存 1  n-1储存 n 
		//核心 就是找到 5 必须有一个地方储存 找到5了 
		for  i:=0;i<len(a);i++{
			ww:=max(a[i],-a[i])	//后边可能有的数被改为负数了 取正数
			a[ww-1]=min(-a[ww-1],a[ww-1])//上一次改为负数就代表有了 别动了
		}
		for  i:=0;i<len(a);i++{
			if a[i]>0{
				ans=append(ans, i+1)
			}
		}
	return ans


}	

 func min(a,b	int)int{
	if a<b {	return a}
	return b
 }
 func max(a,b	int)int{
	if a>b {	return a}
	return b
 }