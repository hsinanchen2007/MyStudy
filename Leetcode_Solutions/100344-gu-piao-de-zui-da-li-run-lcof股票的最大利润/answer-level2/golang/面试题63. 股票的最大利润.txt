### 解题思路
找到数组中最小的数 ， 记录一下子

### 代码

```golang
func maxProfit(num []int) int {

	if len(num) == 0 {
		return 0
	}
	min:=num[0]
	max:=0
	for i := 1; i < len(num); i++ {
		if num[i]- min  > max{
			max = num[i]-min
		}
		if num[i] < min{
			min = num[i]
		}
	}
	return max

}
```