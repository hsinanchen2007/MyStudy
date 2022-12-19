### 解题思路

/*他的最优子结构，就是本次以某个数字结尾的最大序列和的值，其实是依赖上个数字结尾的最大序列和的值+本次结尾的值 和 本次结尾的值 做对比
nums:=[]int{-2,1,-3,4,-1,2,1,-5,4}

-2               lastnum = -2 maxnum = -2
-2   （-2 1） 1   lastnum = 1 （-2+1 和 1对比）   maxnum=1
（-2 1 -3） （1 -3）  -3  lastnum=-2（1+-3和-3做对比） maxnum = 1
（-2 1 -3 4） （1 -3 4） （-3 4） 4  lastnum=4（-2+4和4做对比） maxnum = 4
 */

### 代码

```golang
func maxSubArray(nums []int) int {
    
    lastmaxnum := nums[0] //以某个数字结尾中最大值和的记录
	maxnum :=  nums[0] //目前遍历到某个数字结尾之前所有的最大子序列和的值，即最终结果
	for i:=1;i<len(nums);i++ {
		lastmaxnum = max(lastmaxnum+nums[i],nums[i]) //用上一个以上个数字结尾的最大序列和+本个以nums[i]结尾的序列，和当前值进行比较就可以得出
		maxnum = max(lastmaxnum,maxnum) //最大子序列和的记录和目前以nums[i]结尾最大序列和的比较
	}
	return maxnum

}

func max(x,y int) int {
	if x > y {
		return x
	} else {
		return y
	}
}
```

