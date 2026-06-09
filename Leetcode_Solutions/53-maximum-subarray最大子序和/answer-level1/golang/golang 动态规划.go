应该是用动态规划思想。定义一个概念，f(k)表示以当前元素结尾的子数组的最大值，则f(k)应该等于max(num[k],f(k-1)+num[k])
```
func max(x,y int) int {
	if x>y{
		return x
	}else {
		return y
	}
}
func maxSubArray(nums []int) int {
	//应该是用动态规划思想。定义一个概念，f(k)表示以当前元素结尾的子数组的最大值，则f(k)应该等于max(num[k],f(k-1)+num[k])
	if len(nums)==1{
		return nums[0]
	}
	maxSum:=make([]int,len(nums))
    maxSum[0]=nums[0]
    
	res:=nums[0]
	for i:=1;i<len(nums) ;i++  {
		maxSum[i]=max(nums[i],nums[i]+maxSum[i-1])
		if maxSum[i]>res{
			res=maxSum[i]
		}
	}
	return res

}
```
