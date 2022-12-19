### 解题思路
1. 思路如下：
> a. 将数组排序
> b. 遍历数组，每个数字的索引用 `i` 表示。
> c. 设置双指针 s 和 e，s 指向 i 的下一个数字，e 指向数组的最后一个数字。
> d. 首先计算 ise 三数之和，计算与 target 的差值，如果比当前已有的差值小，则更新差值和结果 sum。
> e. 移动双指针：如果 sum < target，则将左指针 s 右移；如果 sum > target，则将右指针左移；如果 sum == target，则直接返回当前 sum 值，因为题目已经假设仅存在唯一值。

2. 上面需要解释的是指针的移动，试想如果 sum < target，那么将 sum 变大才会更接近 target，反之亦然；由于数组已经提前排序，所以左移右移不会出现问题。
3. 代码如下。排序复杂度为 O(nlogn)；遍历 i 复杂度为 O(n)，内层循环最坏情况复杂度也为 O(n)，所以时间复杂度为 O(n^2)。空间复杂度为O(1)。

### 代码

```golang
func threeSumClosest(nums []int, target int) int {
    // 数组排序
	sort.Ints(nums)
	//  存储差值的最小值
	min := math.MaxInt32
	// 存储结果
	result := 0
	for i := 0; i < len(nums); i++ {
		// 双指针 s 和 e
		// s 从当前遍历结点的下一个开始，e 从最后一个结点开始遍历
		s := i + 1
		e := len(nums) - 1
		for s < e {
			sum := nums[i] + nums[s] + nums[e]
			// 计算得到差值
			diff := 0
			if sum-target < 0 {
				diff = target - sum
			} else {
				diff = sum - target
			}
			// 如果差值比当前最小值小，更新差值
			if diff < min {
				min = diff
				result = sum
			}
			// 移动指针
			if sum < target {
				s++
			} else if sum > target {
				e--
			} else {
				return sum
			}
		}
	}
	return result
}
```