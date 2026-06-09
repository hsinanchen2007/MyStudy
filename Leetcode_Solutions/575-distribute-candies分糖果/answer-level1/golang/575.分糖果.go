### 解题思路

算出糖果的种类数，如果糖果种类小于总糖果数的一半，则妹妹能分得所有种类的糖果，如果糖果种类大于总糖果数的一半，则妹妹只能分得总糖果数得一半，

### 代码

```golang
func distributeCandies(candies []int) int {
	hash := make(map[int]int)
	sum := 0
	for _,i := range candies {
		if _,ok := hash[i];!ok {
			hash[i] = 1
			sum++
		}
	}
	if sum > len(candies) / 2 {
		return len(candies) / 2
	}else {
		return sum
	}
}
```