### 解题思路

遍历数组：
（1）对第一个元素，本身是0右边是0即可种花
（2）对于中间元素，本身是0，左右两边都是0，可以种花
（3）对于最后一个元素，本身是0，左边是0，可以种花

### 代码

```golang
func canPlaceFlowers(flowerbed []int, n int) bool {
	if n > len(flowerbed) {
		return false
	}
	blank := 0
	for i := 0;i < len(flowerbed);i++ {
		if flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == len(flowerbed) - 1 || flowerbed[i + 1] == 0) {
			flowerbed[i] = 1
			blank ++
		}
	}
	return blank >= n
}
```