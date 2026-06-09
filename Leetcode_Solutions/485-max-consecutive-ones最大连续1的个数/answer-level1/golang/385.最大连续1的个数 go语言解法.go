### 解题思路

太简单，不啰嗦直接上代码了。

### 代码

```golang
func findMaxConsecutiveOnes(nums []int) int {
		max := 0
		tmp := 0
		for _,j := range nums {
			if j == 1 {
				tmp++
			}else {
				if tmp > max {
					max = tmp
				}
				tmp = 0
			}
		}
		if tmp > max {
			max = tmp
		}
		return max
}
```