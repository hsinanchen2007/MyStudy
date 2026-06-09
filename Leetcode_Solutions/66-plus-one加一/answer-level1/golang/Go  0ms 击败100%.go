
执行用时 : 0 ms, 在Plus One的Go提交中击败了100.00% 的用户

内存消耗 : 2.2 MB, 在Plus One的Go提交中击败了30.57% 的用户

---------------------------------------------------------------------------------------------------------

# 题意理解

将一个整数拆分成一个数组，每个数字代表一个value。则：123456就是[1,2,3,4,5,6]。

1. 注意，不能转String再转Int后+1，因为再转回Int的时候如果遇到过大的数字会溢出。

我们要考虑传递进来的参数会是：

`[7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6]`

2. 不要使用sort.Sort(sort.Reverse(sort.IntSlice(data)))，它是不稳定的。

3. 用到了一个自定义的布尔值`addOneFlag`来处理溢出的位数。因为[9,9] 加一 是100，那就应该返回[1,0,0]，就由2位变成了3位。



```go

package main

import (
	"testing"
)

func TestFunc(t *testing.T) {
	t.Log(plusOne([]int{9, 9}))
	t.Log(plusOne([]int{1, 2,3}))
	t.Log(plusOne([]int{7, 2, 8, 5, 0, 9, 1, 2, 9, 5, 3, 6, 6, 7, 3, 2, 8, 4, 3, 7, 9, 5, 7, 7, 4, 7, 4, 9, 4, 7, 0, 1, 1, 1, 7, 4, 0, 0, 6}))
}

func plusOne(digits []int) []int {
	if len(digits) == 0 {
		panic("为空的数组不能继续执行")
	}

	var data = make([]int, len(digits))
	dataNum := 0
	addOneFlag := false
	for i := len(digits) - 1; i >= 0; i-- {
		data[dataNum] = digits[i]
		if i == len(digits)-1 {
			if digits[i]+1 > 9 { //如果最后一位+1大于9，说明要进一位，则addOneFlag设为true
				addOneFlag = true
				data[dataNum] = 0
			} else {
				data[dataNum] = digits[i] + 1
			}
		} else {
			if addOneFlag == true {
				if digits[i]+1 > 9 {
					data[dataNum] = 0
				} else {
					data[dataNum] = digits[i] + 1
					addOneFlag = false
				}
			} else {
				data[dataNum] = digits[i]
			}
		}

		if i == 0 && addOneFlag { //如果到了最后一个循环还没有消化掉addOneFlag，说明溢出了，要加一位
			data = append(data, 1)
		}

		dataNum++
	}

	newData := make([]int, len(data))
	newDataNum := 0

	//sort.Sort(sort.Reverse(sort.IntSlice(data)))	//不要用，你可以试试[1,2,3]的输出会不正确，变成了[4,2,1]
	//return data

	//正确反序
	for i := len(data) - 1; i >= 0; i-- {
		newData[newDataNum] = data[i]
		newDataNum++
	}

	return newData
}


```
