如果双循环查找的话时间超时。
一个array保留，另一个转map查找。
```
func findSwapValues(array1 []int, array2 []int) []int {
	sum1,sum2 := 0,0
	res := []int{}
	for i :=range array1{
		sum1 += array1[i]
	}
	for j :=range array2{
		sum2 += array2[j]
	}
	num := sum1-sum2
	if num%2 == 0{
		num = num/2
	}else{
		return res
	}
	temp := make(map[int]int)
	for j := 0 ; j < len(array2) ; j++{
		temp[array2[j]] = j
	}
	for i:=0 ; i < len(array1); i++{
		_ ,ok :=temp[array1[i] - num]
		if ok == true{
			res = append(res, array1[i])
			res = append(res, array1[i] - num)
            return res
		}
	}
    
	return res
}
```
