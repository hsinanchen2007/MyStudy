### 解题思路
此处撰写解题思路

### 代码

```golang
type NumArray struct {
	sum []int
}

// 前缀和
func Constructor(nums []int) NumArray {
	prefixSum := NumArray{
        []int{0},
    }
	for i, v := range nums {
		prefixSum.sum = append(prefixSum.sum, v + prefixSum.sum[i])
	}
	return prefixSum
}

func (this *NumArray) SumRange(i int, j int) int {
	return this.sum[j+1] - this.sum[i]
}
```