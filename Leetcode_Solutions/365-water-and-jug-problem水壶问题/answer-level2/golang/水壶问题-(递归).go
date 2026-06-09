### 解题思路
此处撰写解题思路

### 代码

```golang
func canMeasureWater(x int, y int, z int) bool {
	if x > y {
		x ,y = y,x
	}

	nums := make(map[int]int,0)
	nums[x+y] = 1
    nums[0] = 1

	k := 0
	getMap(nums,x,y,k)

	if nums[z] == 1 {
		return true
	}

	return false
}

func getMap(nums map[int]int,x,y,k int)  {
	if nums[x+k] == 0 {
		nums[x+k] = 1
		if x+k < y {
			getMap(nums,x,y,x+k)
		}
	}

	if x-k > 0 && nums[x-k] == 0 {
		nums[x-k] = 1
		getMap(nums,x,y,x-k)
	}

	if nums[y+k] == 0 {
		nums[y+k] = 1
	}

	if y-k > 0 && nums[y-k] == 0 {
		nums[y-k] = 1
		getMap(nums,x,y,y-k)
	}
}
```