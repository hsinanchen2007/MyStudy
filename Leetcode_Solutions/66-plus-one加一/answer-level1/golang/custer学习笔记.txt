# 错误的示例

![图片.png](https://pic.leetcode-cn.com/c135576b92df518f14377929765ce9e6067c95dea80c5facf139c9bf6deaf6aa-%E5%9B%BE%E7%89%87.png)

```go
func plusOne(digits []int) []int {
	var s, t string
	// 1. 遍历数组，赋值给字符串
	for _, v := range digits {
		s += strconv.Itoa(v)
	}
	// 2. 字符串转换成数字
	num, err := strconv.Atoi(s)
	if err != nil {
		return nil
	}
	// 3. 数字加1再转换成字符串
	t = strconv.Itoa(num + 1)
	// 4. 遍历字符串，返回数组
	ret := make([]int, len(t))
	for i, c := range t {
		n, err := strconv.Atoi(string(c))
		if err != nil {
			return nil
		}
		ret[i] = n
	}
        // 5. 如果无返回值，直接赋值给原数组
	for i := range ret {
		if i < len(digits) {
			digits[i] = ret[i]
		} else {
			digits = append(digits, ret[i])
		}
	}
	return digits
}
```

正确的方法：学习自[@guanpengchn](/u/guanpengchn)

https://leetcode-cn.com/problems/two-sum/solution/hua-jie-suan-fa-66-jia-yi-by-guanpengchn/

1. 末位无进位，则末位加一即可，因为末位无进位，前面也不可能产生进位，比如 45 => 46
2. 末位有进位，在中间位置进位停止，则需要找到进位的典型标志，即为当前位 %10 后为 0，则前一位加 1，直到不为 0 为止，比如 499 => 500
3. 末位有进位，并且一直进位到最前方导致结果多出一位，对于这种情况，需要在第 2 种情况遍历结束的基础上，进行单独处理，比如 999 => 1000

```go
func plusOne(digits []int) []int {
    ll := len(digits)
    for i := ll - 1; i >= 0; i-- {
        digits[i]++ 
        digits[i] %= 10
        if digits[i] != 0 {
            return digits
        }
    }
    // digits = make([]int, ll+1)
    // digits[0] = 1
    digits = append([]int{1}, digits...)
    return digits
}
```

学习自[@elliotxx](/u/elliotxx)

https://leetcode-cn.com/problems/two-sum/solution/0ms11xing-dai-ma-go-shi-xian-by-elliotxx/

```go
func plusOne1(digits []int) []int {
    for i := len(digits) - 1; i >= 0; i-- {
        if digits[i] < 9 {
            // 当前位置不用进位，+1，然后直接返回
            digits[i]++
            return digits
        } else {
            // 要进位，当前位置置0
            digits[i] = 0
        }
    }
    return append([]int{1}, digits...)
}
```