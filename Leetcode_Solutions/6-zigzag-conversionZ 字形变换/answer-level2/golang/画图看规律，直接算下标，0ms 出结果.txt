> 原文发布于我的博客： [leetcode-cn 题解 6. Z 字形变换](https://blog.by24.cn/archives/leetcode-zigzag-conversion.html)

## 解题思路

这道题其实相对还是比较简单的，有很多种解法，这里先只说其中一种

首先还是老样子，构造测试数据，画图，我们假设字符串的内容就和下标一样，方便观察。

![image.png](https://pic.leetcode-cn.com/cae8d5c0899c90c3aa05029dde3abf542203f28b93f58de50e485cba9b45d787-image.png)


这是按照题目给出的样式进行排列的，可以看到的是，在中间的斜线部分，每一列每一行其实只有一个字符，那我们就可以把它压缩一下。

![image.png](https://pic.leetcode-cn.com/e78b86c6186b6a2d43a1d14676848640170c886bff207e50a9653df91cbe6359-image.png)


压缩之余，我顺便给它上了个颜色，可以看到，这些字符其实是 6 个一组，不断重复排列下去的。

那么接下来，我们设行数为 `n` ，每组的长度为 `q`，很显然 `q = 2n-2 `。

我们把 n 和 q 带进去继续画图，因为算式比较长，每个格子只好变胖一点点了。

![image.png](https://pic.leetcode-cn.com/864186c02b3ef7da0015c279115a7b5635a96ab86cbbf6c2d055e6dd51e9eefb-image.png)


其实到这一步的时候已经比较明朗了，每一横行字符的下标其实可以直接算出来，只需要不断的计算后面那一组就可以了，至于第一行和最后一行，特殊处理下就好。

## 解答

```go
func convert(s string, numRows int) string {
	if numRows == 1 || len(s) <= numRows{
		return s
	}
	groupLen := numRows*2 - 2
	groupNum := int(math.Ceil(float64(len(s)) / float64(groupLen)))
	var ansString []byte

	for i := 0; i < numRows; i++{
		//计算第 i 行字符串
		for j := 0; j < groupNum; j++  {
			//计算第 j 组字符串
			charIndex := groupLen*j + i
			if charIndex >= len(s) {
				continue
			}
			ansString = append(ansString, s[charIndex])
			if i != 0 && i != numRows-1 {
				charIndex = groupLen*(j+1) - i
				if charIndex < len(s) {
					ansString = append(ansString, s[charIndex])
				}
			}
		}

	}
	return string(ansString)
}

```

这里其实还可以做点小优化，其实并不需要计算出组数，下标爆了就 continue 就好了，可以直接 while 循环搞起。

```go
func convert(s string, numRows int) string {
	if numRows == 1 || len(s) <= numRows{
		return s
	}
	groupLen := numRows*2 - 2
	var ansString []byte

	for i := 0; i < numRows; i++{
		//计算第 i 行字符串
		left := i
		right := groupLen - left
		for  {
			if left >= len(s) {
				break
			}
			ansString = append(ansString, s[left])
			left += groupLen
			if i != 0 && i != numRows-1 {
				if right >= len(s) {
					break
				}
				ansString = append(ansString, s[right])
				right += groupLen
			}
		}
	}
	return string(ansString)
}
```

实际中这两个版本跑起来都蛮快的，并没有太大区别

![image.png](https://pic.leetcode-cn.com/5125cc8e62ad3632cdd9c3e6191cdf50e45c6e3f3d31deef43690c16bb4e54e3-image.png)
