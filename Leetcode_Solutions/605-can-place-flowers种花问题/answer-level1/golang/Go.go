看到题解里很好的一个思路是，在数组首尾各加一个零，然后从1开始遍历到倒数第二个位置。
但是这题，我在逐个遍历的情况下，时间复杂度为53%，于是，增加了跳跃，当元素为1或者被修改为1的情况下，该元素的下一个位置一定不能种花，基于此进行跳跃。更改后的代码时间复杂度99%

```golang
func canPlaceFlowers(flowerbed []int, n int) bool {
	if n==0{
		return true
	}
	pt1:=0
	for pt1<len(flowerbed){
		if flowerbed[pt1]==0&&(pt1==0||flowerbed[pt1-1]==0)&&(pt1==len(flowerbed)-1||flowerbed[pt1+1]==0){
			flowerbed[pt1]=1
			n--
			if n==0{
				return true
			}
		}
		if flowerbed[pt1]==1{
			pt1++
		}
		pt1++
	}
	return false
}
```