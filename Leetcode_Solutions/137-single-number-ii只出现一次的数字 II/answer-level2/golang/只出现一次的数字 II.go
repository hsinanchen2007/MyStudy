### 解题思路
计数

### 代码

```golang
func singleNumber(nums []int) int {
	cntMap := make(map[int]int)
	for _, n := range nums {
		cntMap[n]++
	}
	for k,v:=range cntMap {
		if v == 1{
			return k
		}		
	}
	return 0
}

```