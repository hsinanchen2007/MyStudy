### 解题思路
此处撰写解题思路
//到这算出来的left和right的平方是最接近x的
所以用left或者是right都可以
if left * left > x {
		return left -1
	} else {
		return left
	}
### 代码

```golang
func mySqrt(x int) int {
      left,right := 0,x
	if x <= 1 {
		return x
	}

	middle := x/2

	for left < right {
		middle = (left+right)/2
		if middle * middle < x {
			left = middle+1 //计算middle 到right的值
		}  else if middle * middle == x {
			return middle
		}  else {
			right = middle-1 //计算left到middle的值
		}
	}

	if left * left > x {
		return left -1
	} else {
		return left
	}
}
```