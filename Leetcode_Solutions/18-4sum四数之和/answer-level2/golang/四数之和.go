### 思路
滑动窗口 + 二分法查找指定数值
### 完整代码
```
func fourSum(nums []int, target int) [][]int {
	i := 0  // 左指针
	j := 0  // 右指针
	mid := 0 // 中间值指针
	midLeft := 0 
	midRight := 0
	numsLen := len(nums)
	result := make([][]int,0,0)
	if numsLen < 4 {    // 元素数不符合
		return result
	}
	sortNums := sort.IntSlice(nums)
	sortNums.Sort()
	for k := 0; k < numsLen - 3 /* 如果后面不够4个元素 提前结束*/; k++ {
		if k >0 && nums[k] == nums[k - 1] { // 当前元素与上个元素重复，不用在查找， 因为查到的也是一样的数据
			continue
		}
		if nums[k] + nums[k+1] + nums[k+2] + nums[k+3] > target { // 最小四个值之和 大于目标值
			return result
		}
		mid = 0
		midLeft  = 0
		midRight = 0
		for i = k+1; i < numsLen - 2 /*保证i后面至少还需要2个元素*/; i++ {
            if i > k + 1 && nums[i] == nums[i - 1] { // 当前元素与上个元素重复，不用在查找， 因为查到的也是一样的数据
                continue
            }
			j = numsLen - 1
			for i < j-1 {
				if nums[k] + nums[i] + nums[j] + nums[j-1] < target  {
					break
				}
				if nums[k] + nums[i] + nums[j] >= target && nums[i] > 0  {
					j--
					continue
				}
				needNumber := target - ( nums[k] + nums[i] + nums[j] )
				// nums[k] + nums[i] + nums[j] < target
				// 在 (i,j)内找到一个符合 nums[k] + nums[i] + nums[j] + nums[mid] == target即可
				midLeft = i+1
				midRight = j-1
				// 二分查找 查到符合的值
				for midLeft <= midRight {
					mid = midLeft + ( (midRight - midLeft) >> 1)
					if nums[mid] > needNumber {
						midRight = mid - 1
						continue
					}
					if nums[mid] < needNumber {
						midLeft = mid + 1
						continue
					}

					if nums[mid] == needNumber {
						// 跳过重复的
						lastIndex := len(result) - 1
						if lastIndex >= 0 && result[lastIndex][0] == nums[k] &&
							result[lastIndex][1] == nums[i] &&
							result[lastIndex][2] == nums[mid] &&
							result[lastIndex][3] == nums[j]{
							break
						}
						result = append(result, []int{
							nums[k],
							nums[i],
							nums[mid],
							nums[j],
						})
						break
					}

 				}
				j--
			}
		}
	}
	return result
}
```
### 执行结果
![image.png](https://pic.leetcode-cn.com/fe50b76614124bd037382706ca501dc5e8a6c63775a84897abeb8a5ec46dee21-image.png)
