假设D的长度为d，N的位数为n，方法描述如下：
1. 先组合比N位数小的数字，这个比较简单，从1位数组累加到n-1位数，计算为d^1 + d^2 + ... + d^(n-1)
2. 再组合位数为N且小于N的数字，将数字N从最高位开始取出，逐一与D中的元素进行比较
3. 如果D中的元素比当前数组N取出的数值小（假设目前在N的第i位），则表示第i位以下的低位可以用D中的数字任意组合，数目为d^(n-i)
4. 如果D中的元素与当前数组N取出的数组相等（假设当前在N的第i位），则表示此时需要固定第i位，用1)中的类似的方法判断第i-1位，并标记标签
5. 如果D中的元素比当前数组N取出的数值大（假设目前在N的第i位），则无需继续向下比较，因为用D后面元素组合的数字肯定N大
3. 如果比较完了之后还标签为已置，则表示最终组合的数字与N相等，最大为N的数组组合还需加1

具体代码如下：


```
func atMostNGivenDigitSet(D []string, N int) int {
	var res int
	str := strconv.Itoa(N)

	lenN := len(str)
	lenD := len(D)

	for i := 1; i < lenN; i++ {
		res += int(math.Pow(float64(lenD), float64(i)))
	}

	for i := 0; i < lenN; i++ {
		isSame := false
		for _, v := range D {
			if v < string(str[i]) {
				res += int(math.Pow(float64(lenD), float64(lenN-1-i)))
			} else if v == string(str[i]) {
				isSame = true
			} else {
				break
			}
		}
		if !isSame {
			return res
		}
	}
	return res + 1
}
```

![image.png](https://pic.leetcode-cn.com/0d0ccaf4cc44321f38dd8fc879488eeddf1f707ddda365425bba1f4abbf9c6ac-image.png)
