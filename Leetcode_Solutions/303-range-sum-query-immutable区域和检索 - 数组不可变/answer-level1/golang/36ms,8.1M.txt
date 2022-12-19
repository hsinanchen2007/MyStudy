### 解题思路
此处撰写解题思路
保存0-i的值 this.SumRange(i,j)=this.SumRange(0,j)-this.SumRange(0,i-1)

### 代码
```golang
type NumArray struct {
	nums []int
	m map[string]int
}


func Constructor(nums []int) NumArray {
	return NumArray{nums:nums,m: map[string]int{}}
}


func (this *NumArray) SumRange(i int, j int) int {
	if v,ok:=this.m[string(i)+"|"+string(j)];ok{
		return v
	}
	if i==0{
		sum:=0
		for i:=0;i<=j;i++{
		    sum+=this.nums[i]
		}
		this.m[string(i)+"|"+string(j)]=sum
		return sum
	}
	this.m[string(i)+"|"+string(j)]=this.SumRange(0,j)-this.SumRange(0,i-1)
	return this.m[string(i)+"|"+string(j)]
}
```

```golang
type NumArray struct {
	nums []int
	m map[int]int
}


func Constructor(nums []int) NumArray {
	sum:=0
	m:=map[int]int{}
	for i:=0;i<len(nums);i++{
	    sum+=nums[i]
		m[i]=sum
	}
	return NumArray{nums:nums,m: m}
}


func (this *NumArray) SumRange(i int, j int) int {
	if i==0{
		return this.m[j]
	}
	return this.SumRange(0,j)-this.SumRange(0,i-1)
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(i,j);
 */
```