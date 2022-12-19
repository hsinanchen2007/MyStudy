### 43.字符串相乘
题意：禁止使用标准库完成大数乘法

解题思路：模拟竖乘运算过程

拿两个数在草稿纸上演算一遍，模拟这个过程，先算出被乘数与乘数每一位的结果然后再累加(2*3表示3个2，2是被乘数，3是乘数)，注意进位，开始没考虑清楚进位WA了两次
36ms 6.6M 
```
func multiply(num1 string, num2 string) string {
	len1 := len(num1)
	len2 := len(num2)
	if len1 == 1 && num1[0] == '0' {
		return "0"
	}
	if len2 == 1 && num2[0] == '0' {
		return "0"
	}

	tempResult := make([][]byte, 0)
	for i := len2 - 1; i >= 0; i-- {
		add := 0
		digit := len2 - i
		tempArr := make([]byte, 0)
		for j := len1 - 1; j >= 0; j-- {
			temp := int((num1[j]-48)*(num2[i]-48)) + add
			mod := temp % 10
			add = temp / 10
			//fmt.Printf("temp:%d mod:%d add:%d\n", temp, mod, add)

			tempArr = frontInsert(tempArr, byte(mod+48))
			for digit > 1 {
				tempArr = backInsert(tempArr, '0')
				digit--
			}
		}
		if add > 0 {
			tempArr = frontInsert(tempArr, byte(add+48))
		}
		tempResult = append(tempResult, tempArr)
	}
	//fmt.Println(tempResult)
	result := []byte{'0'}
	for _, v := range tempResult {
		//before := result
		result = add(result, v)
		//fmt.Printf("%+v + %+v = %+v\n", before, v, result)
	}
	return string(result)

}

func add(num1 []byte, num2 []byte) []byte {
	len1 := len(num1)
	len2 := len(num2)
	for len1 < len2 {
		num1 = frontInsert(num1, '0')
		len1++
	}
	for len1 > len2 {
		num2 = frontInsert(num2, '0')
		len2++
	}
	//fmt.Println(num1)
	//fmt.Println(num2)
	result := make([]byte, 0)
	add := 0
	for i := len1 - 1; i >= 0; i-- {
		temp := int(num1[i]-48) + int(num2[i]-48) + add
		mod := temp % 10
		add = temp / 10
		result = frontInsert(result, byte(mod+48))
	}
	if add > 0 {
		result = frontInsert(result, byte(add+48))
	}
	//fmt.Println(result)
	return result
}

func frontInsert(arr []byte, v byte) []byte {
	a := make([]byte, len(arr)+1)
	a[0] = v
	copy(a[1:], arr[:])
	return a
}

func backInsert(arr []byte, v byte) []byte {
	a := make([]byte, len(arr)+1)
	at := copy(a[0:], arr[:])
	a[at] = v
	return a
}
```
上面版本实现比较复杂，因为是完全模拟竖乘，所以增加了大数相加，前置插入和后置插入操作。实际两个数相乘，假设两数长度分别为len1和len2，结果长度范围一定在[max(len1,len2),len1+len2]之间，注意num1
和num2较小的时候需要去除首位0，优化版本如下
4ms 3M
```
func multiply(num1 string, num2 string) string {
	len1 := len(num1)
	len2 := len(num2)
	if num1 == "0" || num2 == "0"{
		return  "0"
	}

	result := make([]int,len1 + len2)
	for i := len2 - 1; i >= 0; i-- {
		for j := len1 - 1; j >= 0; j-- {
			temp := int(num2[i] - '0') * int(num1[j] - '0') + result[i + j + 1]
			if temp >= 10{
				result[i + j] += temp / 10
				result[i + j + 1] = temp % 10
				//fmt.Printf("add:%d mod:%d\n",temp / 10,temp%10)
			}else{
				result[i + j + 1] = temp
			}
		}
	}
	//fmt.Println(result)
	//num1和num2较小时，去除首位0
	if result[0] == 0{
		result = result[1:]
	}
	str := ""
	for _,v := range result{
		str += strconv.Itoa(v)
	}
	return str
}
```