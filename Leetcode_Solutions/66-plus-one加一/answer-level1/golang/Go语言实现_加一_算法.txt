思路：首先倒序循环判断当前数字是否为9，如果为9就将该数字保存到一个临时切片中，如果不为9，那么就将该数字加一放入该切片中并记下当前的索引(index)位置，然后结束循环(这里最坑爹的是Go语言只有一个append()函数添加元素，而且还是在末尾添加，不然就更简单了)，首先判断那个index是否为-1（至于为什么一开始初始化为-1呢，大家可以去仔细想一下），如果为-1，说明最开始的数组一定是9999...类型的，然后把要返回的那个切片首位放1，后面的放临时切片，如果不为-1，那就把原切片索引从0到index的部分先添加到返回的切片中，然后再把临时切片按倒序加入到然后切片后面，最后返回即可
```
func plusOne(digits []int) []int {
    var tmp int
	var index = -1
	lenth := len(digits)
	var resNum = make([]int, 0, len(digits)+1)
	var tmpNum = make([]int, 0, len(digits)+1)
	for i := lenth - 1; i >= 0; i-- {
		tmp = digits[i]
		if tmp == 9 {
			tmpNum = append(tmpNum, 0)
		} else {
			tmpNum = append(tmpNum, tmp+1)
			index = i
			break
		}
	}
	if index == -1 {
		resNum = append(resNum, 1)
		resNum = append(resNum, tmpNum[:]...)
	} else {
		resNum = append(resNum, digits[:index]...)
		for i := len(tmpNum) - 1; i >= 0; i-- {
			resNum = append(resNum, tmpNum[i])
		}
	}
	return resNum
}
```
