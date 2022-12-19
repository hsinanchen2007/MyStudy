### 解题思路
刚开始觉得这个题很简单，但是做了之后，觉得不应该这么简单，应该能优化，提交看了看，果然大家的时间都那么快，
这个题目的关键点在于：这个SumRange函数会被多次使用的，所以我们如果提前打表的话，就可以节省时间。
代码如下，浪费了第一个的存储空间，但是不需要额外的另一个变量去做中间存储，也不需要麻烦的判断。
这个代码能更快，就是直接可以make一个很长的slice，这样不需要每次append时都重新分配地址的耗时。
但是那样肯定会消耗内存。

### 代码

```golang
type NumArray struct {
	Value []int
}

func Constructor(nums []int) NumArray {
	// 一维前缀和
	numa := NumArray{[]int{0}}  // 浪费第一个空间
	for i, v := range nums {
		numa.Value = append(numa.Value, v + numa.Value[i])
	}
	return numa
}

func (this *NumArray) SumRange(i int, j int) int {
	return this.Value[j+1] - this.Value[i]
}
/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(i,j);
 */
```