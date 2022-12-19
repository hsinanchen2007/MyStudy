1. 如果两个字符串的长度差值大于1，则直接返回`false`

2. 先从左边开始比较
    1. 如果这个指针最终走到了两个字符串的末尾，则返回`true`
    2. 否则，两字符串中间有差异
    
3. 从右边开始比较。走到这一步，说明两字符串必然存在差异。需要判断的是，左边指针指向的差异点，与右边指针指向的差异点，是否相同。
右边的指针会有两个，与哪一个比较呢？
- 对于等长的字符串，两个右指针的值是相等的，因此与两个右指针的任意一个比较都是可以的。如果`left`与`right`相等，则说明左右两个指针指向同一个差异。 
- 对于不等长的字符串，需要与较长的字符串的右指针比较。因为较短的字符串，此时的`right` < `left`。可以参照下图：

![image.png](https://pic.leetcode-cn.com/2cb9b3d4930edf600253a9986b85fed8a9d984f0996bfdc1bbdbc9c0d2b18f22-image.png)


```go
func oneEditAway(first string, second string) bool {
	size1, size2 := len(first), len(second)
	if size1 > size2+1 || size2 > size1+1 {
		return false
	}

	left := 0
	for {
		if left >= size1 || left >= size2 || first[left] != second[left] {
			break
		}
		left++
	}

	if left == size1 && left == size2 {
		return true
	}

	right1, right2 := size1-1, size2-1
	for {
		if right1 < 0 || right2 < 0 || first[right1] != second[right2] {
			break
		}
		right1--
		right2--
	}

	return (right1 >= right2 && right1 == left) || (right1 < right2 && right2 == left)
}
```
