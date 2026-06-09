**官方介绍**
```
官方F1：通过遍历，逐个判断

官方F2: 菜鸡看不懂……
```
**新思路**
```
1.好数由0,1,2,5,6,8,9构成，主动通过递归构建新的好数
2.判断合成的好数是否成立
    不成立数：全部由1，0，8构成

时间复杂度较低（应该比官方低），递归空间复杂度高
```

**代码**
```
func is0or1or8(num int) bool {
	var s = strconv.Itoa(num)
	for _,value := range s{
		if value != '0' && value != '1' && value != '8'{
			return false
		}
	}
	return true
}

func helper(times *int,curNum int,n int)  {
	if curNum > n{
		return
	}else if !is0or1or8(curNum){
		fmt.Println(curNum)
		*times++
	}
	for _,value := range nums{
		if curNum == 0 && value == 0{
			continue
		}
		helper(times,curNum*10+value,n)
	}

}
var nums = []int{0,1,2,5,6,8,9}

func rotatedDigits(N int) int {
	var times = 0
	helper(&times,0,N)
	return times
}
```
