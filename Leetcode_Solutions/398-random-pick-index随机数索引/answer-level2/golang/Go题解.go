蓄水池抽样，和382题感觉上没什么变动

```golang
type Solution struct {
	arr []int
}


func Constructor(nums []int) Solution {
	return Solution{arr:nums}
}


func (this *Solution) Pick(target int) int {
	res:=-1
	temp:=1
	for i:=0;i<len(this.arr);i++ {
		if this.arr[i]==target {
			if res==-1 {
				res=i
			}else{
				temp++
				if rand.Intn(temp)==0{
					res=i
				}
			}
		}
	}
	return res
}


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.Pick(target);
 */
```