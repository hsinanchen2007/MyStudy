**1、按列求解，**
这种方法比较直观和容易理解，比按行求解思路要清晰；只是时间复杂度为O(N2)
不太明白的是，内存消耗为啥这么搞，这种方法没有额外申请空间，空间复杂度应该是O(1)啊

```golang
func trap(height []int) int {
	if len(height) <= 2 {
		return 0
	}

	result := 0
	maxLeft := -1
	maxRight := -1
	for i := 1; i < len(height) - 1; i++ {
		// 左边最大值可以通过前面的值求出
		if maxLeft == -1 || height[i - 1] > maxLeft {
			maxLeft = height[i - 1]
		}

		maxRight = 0
		// 右边最大值需要遍历
		for j := i + 1; j < len(height); j++ {
			if height[j] > maxRight {
				maxRight = height[j]
			}
		}
		minBound := maxLeft
		if minBound > maxRight {
			minBound = maxRight
		}
		if minBound > height[i] {
			result += minBound - height[i]
		}
	}

	return result
}
```

**2、动态规划**
```golang
func trap(height []int) int {
	if len(height) <= 2 {
		return 0
	}

	dpLeft := make([]int, len(height))
	dpRight := make([]int, len(height))
	dpLeft[0] = 0 // 最左边元素的左最大值是0，因为它左边没有元素
	// 遍历，生成dpLeft
	for i := 1; i < len(height); i++ {
		if height[i - 1] > dpLeft[i - 1] {
			dpLeft[i] = height[i - 1]
		} else {
			dpLeft[i] = dpLeft[i - 1]
		}
	}
	dpRight[len(height) - 1] = 0 // 最右边元素的右最大值是0，因为它右边没有元素
	// 遍历，生成dpRight
	for i := len(height) - 2; i >= 0; i-- {
		if height[i + 1] > dpRight[i + 1] {
			dpRight[i] = height[i + 1]
		} else {
			dpRight[i] = dpRight[i + 1]
		}
	}
	
	result := 0
	for i := 1; i < len(height) - 1; i++ {
		if height[i] < dpLeft[i] && height[i] < dpRight[i] {
			minBound := dpLeft[i]
			if minBound > dpRight[i] {
				minBound = dpRight[i]
			}
			result += minBound - height[i]
		}
	}

	return result
}
```

**3、改进动态规划**
```golang
func trap(height []int) int {
	if len(height) <= 2 {
		return 0
	}

	maxLeft := -1 // 左边最大值可以随时求出，不必用dp的方式求出，既省了dpLeft所需要的空间，又省一次遍历的时间
	dpRight := make([]int, len(height))
	dpRight[len(height) - 1] = 0
	for i := len(height) - 2; i >= 0; i-- {
		if height[i + 1] > dpRight[i + 1] {
			dpRight[i] = height[i + 1]
		} else {
			dpRight[i] = dpRight[i + 1]
		}
	}

	result := 0
	for i := 1; i < len(height) - 1; i++ {
		if maxLeft < 0 || maxLeft < height[i - 1] {
			maxLeft = height[i - 1]
		}
		if height[i] < maxLeft && height[i] < dpRight[i] {
			minBound := maxLeft
			if minBound > dpRight[i] {
				minBound = dpRight[i]
			}
			result += minBound - height[i]
		}
	}

	return result
}
```

不断改进的效果如下：
![image.png](https://pic.leetcode-cn.com/7a2e1237de2e73f9847264259115a841d0f3231be6a19eeec662acefec0a8516-image.png)

但空间占用一直显示很高，不知道怎么优化；对于最开始的按列求解来说，只需要两个额外的int变量，为啥也占用那么多空间呢
![image.png](https://pic.leetcode-cn.com/850a53bed460c587a5f6ca32f674df5e3daa537a36926a526ca9b1658a7425ec-image.png)


