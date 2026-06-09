思路：
 - 排序。之后计算三数之和时，排除一些离目标太远的结果
 - 计算距离。得到离目标比较近的结果集后，做与目标距离（数轴上的距离）计算，最小的距离即为最终答案


> 做了优化，运行时间减半，内存占用降低 40%

![屏幕快照 2019-11-20 22.18.22.png](https://pic.leetcode-cn.com/3e4c73c2831a88e7fa5e1e9834852f132a2ed9fb9c780e99e107e6d1a707fa0d-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-11-20%2022.18.22.png)



**优化后：**
```go []
func threeSumClosest(nums []int, n int) int {
	quickSort(nums)
	var (
        minDis = -1
        result int
    )
	for i := 0; i < len(nums)-1; i++ {
		var head, end = i + 1, len(nums) - 1

		for head < end {
			sum := nums[i] + nums[head] + nums[end]
			if sum == n {
				return sum
			}

			if sum > n {
				end--
			}

			if sum < n {
				head++
			}
            
            d := twoNumDistance(sum,n) // 每次计算三数之和时 计算距离并与当前最小距离对比
            if minDis == -1 || d < minDis{
                minDis = d
                result = sum
            }
		}
	}

	return result
}

func twoNumDistance(a, b int) int {
	if a > b {
		return a-b
	}

	return b-a
}

func quickSort(nums []int) {
	ln := len(nums)
	if ln < 2 {
		return
	}

	var (
		tag       = nums[0]
		head, end = 0, ln - 1
	)

	for i := 1; i <= end; {
		if nums[i] < tag {
			// swap
			nums[head], nums[i] = nums[i], nums[head]
			head++
			i++
		} else {
			nums[end], nums[i] = nums[i], nums[end]
			end--
		}
	}

	quickSort(nums[:head])
	quickSort(nums[head+1:])
}
```

**优化前：**

```go []

func threeSumClosest(nums []int, n int) int {
	quickSort(nums)
	var allPossible []int
	for i := 0; i < len(nums)-1; i++ {
		var head, end = i + 1, len(nums) - 1
		for head < end {
			sum := nums[i] + nums[head] + nums[end]
			if sum == n { // 若果正好得到与 n 相等的结果 立刻返回
				return sum
			}

			if sum > n { // 结果大于 n，尾指针向前移
				end--
			} else { // 结果小于 n 头指针向后移
				head++
			}

			allPossible = append(allPossible, sum)
		}
	}

	var (
		result int // 结果
		minDis int // 最小距离
	)
	for i, el := range allPossible { // 优化后 去掉此循环，在计算三数之和时做该逻辑
		dis := twoNumDistance(el, n)

        if i == 0 || dis < minDis { // 第一个元素或当前距离小于最小距离，则赋值
            minDis = dis
            result = el
        }
		
	}

	return result
}

// 距离计算
// 第一版写了个比较愚蠢的方法，脑子没有转换过来，其实大数减小数即为 两数之间的距离
func twoNumDistance(a, b int) int {
	if a == b {
		return 0
	}
	var left, right, dis = a, b, 0

	if a > b {
		left, right = b, a
	}

	for left < right {
		left++
		dis++
	}

	return dis
}
// 排序
func quickSort(nums []int) {
	ln := len(nums)
	if ln < 2 {
		return
	}

	var (
		tag       = nums[0]
		head, end = 0, ln - 1
	)

	for i := 1; i <= end; {
		if nums[i] < tag {
			// swap
			nums[head], nums[i] = nums[i], nums[head]
			head++
			i++
		} else {
			nums[end], nums[i] = nums[i], nums[end]
			end--
		}
	}

	quickSort(nums[:head])
	quickSort(nums[head+1:])
}

```