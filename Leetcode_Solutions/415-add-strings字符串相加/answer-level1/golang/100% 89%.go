#F1

##思路

```
1. string --> []byte
2. 计算最大、最小数组
3. 反转
4. 计算 按照最大[]的计算（最小[]的不足，补0）
5. 反转
```

```
func reverse(nums []byte)  {
	for i:=0;i<len(nums)/2;i++  {
		nums[i],nums[len(nums)-i-1] = nums[len(nums)-i-1],nums[i]
	}
}

func addStrings(num1 string, num2 string) string {
	var maxSlice,minSlice []byte
	if len(num1) > len(num2){
		maxSlice = []byte(num1)
		minSlice = []byte(num2)
	}else{
		maxSlice = []byte(num2)
		minSlice = []byte(num1)
	}
	reverse(maxSlice)
	reverse(minSlice)
	var tag byte = 0
	var temp,tempMin byte
	for i:=0;i<len(maxSlice) ;i++  {
		if i >= len(minSlice){
			tempMin = '0'
		}else{
			tempMin = minSlice[i]
		}
		temp = maxSlice[i] + tempMin - '0' + tag
		if temp > '9'{
			maxSlice[i] = temp - 10
			tag = 1
		}else{
			maxSlice[i] = temp
			tag = 0
		}
	}
	if tag ==1{
		maxSlice = append(maxSlice, '1')
	}

	reverse(maxSlice)
	return string(maxSlice)
}
```

