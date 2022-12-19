### 解题思路
go防御式编程思想
### 代码

```golang
func canPlaceFlowers(flowerbed []int, n int) bool {
	flowerbed = append([]int{0}, append(flowerbed, 0)...)
	l := len(flowerbed)
	for i := 1; i < l-1; i++ {
		if flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0 {
			flowerbed[i] = 1
			n--
		}
	}
	return n <= 0
}
```