DFS,回溯，剪枝
思路首先是DFS的全排列，然后留下所有数组长度为k的
这样很明显时间复杂度就不会低了，这时候就需要去剪枝
剪枝这里个人认为可以分为两种类型：
一：当我们的数组长度达到k了就可以剪枝了，即len(*arr)==k
二：如果始终达不到k呢？比如当n为8，k为5的时候，我们发现，如果DFS到数组[5,6]了，那么就算把剩下7、8全部填进去，也不能满足数组长度等于5的条件。那么这里剪枝的规律就是：k-len(*arr)>max-n+1，max就是8，n表示当前填的是第几位。
空间复杂度优化：我们可以省略掉创建数组，当第n次的时候，我们发现，我们只能选择填n或者不填，这给了我们省略创建数组的可能性

代码如下：
```
func combine(n int, k int) [][]int {
	if k>n {
		return nil
	}
	var res [][]int
	var arr []int
	if n==0 {
		return [][]int{{}}
	}
	getCombine(1,k,&arr,&res,n)
	return res
}

func getCombine(n int,k int,arr *[]int,res *[][]int,max int){
	if len(*arr)==k {
		temp:=make([]int,len(*arr))
		copy(temp,*arr)
		*res=append(*res, temp)
		return
	}
	 if k-len(*arr)>max-n+1{
		 return
	 } 
	 //下面屏蔽的代码是剪枝方式，但完全可以用上面的剪枝方式取代，而且上面更优。
	//if n>max {
	//	return
	//}
	getCombine(n+1,k,arr,res,max)
	*arr= append(*arr, n)
	getCombine(n+1,k,arr,res,max)
	res2:=*arr
	res2=res2[:len(res2)-1]
	*arr=res2
}
```
