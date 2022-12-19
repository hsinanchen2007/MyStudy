思路：头尾双指针，逐渐缩小。一次遍历，即可找到解。

```
func twoSum1(numbers []int, target int) []int {
	for cursorLeft, cursorRight := 0, len(numbers)-1; cursorLeft < cursorRight; cursorLeft++ {
		// 本轮所需要找的值
		numNeed := target - numbers[cursorLeft]
		for {
			if numbers[cursorRight] > numNeed {
				// 因为有序，所以该值一定在右指针的当下或左边
				cursorRight--
			} else {
				// 当右指针停止递减的时候判断是否满足返回要求
				// 需要注意：如果不满足要求，左指针+1。由于是升序数列，那么下一个numNeed一定在当下的右指针左侧或当下
				if numbers[cursorRight] == numNeed {
					return []int{cursorLeft + 1, cursorRight + 1}
				}
				break
			}

		}
	}
	// 当左指针和右指针相遇时，说明该数组无满足条件的元素。
	// 这样遍历一遍，就可以找到解

	return nil
}

```
![image.png](https://pic.leetcode-cn.com/e547da9a7b875509fc353cb763a67cffcec896bd185f8bb8e4ad7179f57622a3-image.png)
