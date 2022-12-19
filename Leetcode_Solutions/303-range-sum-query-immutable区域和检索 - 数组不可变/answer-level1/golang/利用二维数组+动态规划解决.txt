### 解题思路
因为说了会调用很多次，那么查询次数最多，需要O（1）的时间复杂度


### 代码

```golang


// 利用动态规划来做
type NumArray struct {
	dp [][]int //[i,j] 表示从i到j的和 i<=j
	nums []int
	len int
}


func Constructor(nums []int) NumArray {
	l := len(nums)

	c := NumArray{
		len:l,
		nums: nums,
	}
	if l > 0{
		c.dp =  make([][]int,l)
		c.makeArr(l,l)
		c.cal()
	}
	return c
}

func (this *NumArray) cal()  {
	l := len(this.nums)
	this.dp[0][0] = this.nums[0]
	for i:=1;i<l;i++{
		this.dp[0][i] = this.dp[0][i-1]+this.nums[i]
	}
	for i:=1;i<l;i++{
		for j:=i;j<l;j++{
			if i == j{
				this.dp[i][j] = this.nums[i]
			}else{
				this.dp[i][j] = this.dp[i][j-1]+this.nums[j]
			}
		}
	}
}

func (this *NumArray) makeArr(l1,l2 int)  {
	for i:=0;i<l1;i++{
		this.dp[i] = make([]int,l2)
	}
}


// 这个操作应该是不能计算的  直接返回二维数组中的值
func (this *NumArray) SumRange(i int, j int) int {
	// 已经规定来i<j  所以不用判断了
	if this.len>0{
		return this.dp[i][j]
	}
	return -1
}

```