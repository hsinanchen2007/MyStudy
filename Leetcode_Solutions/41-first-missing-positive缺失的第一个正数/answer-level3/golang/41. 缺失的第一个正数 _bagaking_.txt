这道题的难点主要在审题

一开始没好好看题把问题复杂化惹, 当成了在线+分析🤦‍♀️, 花了不少时间处理边界和花样剪枝

回头看下了题, get 到所有的数都必须落在 [1, n + 1] 以后剩下的就比较无脑了

## 方法 1: 状态压缩

首先是 求正数, 所有 <= 0 的输入可以忽略

然后因为值一定落在 [1, n + 1], n + 1 又不需要记录状态, 所以共有 n 个状态, 每个状态还都是二值值表示的

所以前面忽略的 < 0 状态完全可以利用起来, vi - 1 对应的位置正好是 [0, n - 1], 正好可以用他们的符号值来表示该位置对应数值的存在性

归类的话, 勉强算是变种的状态压缩吧

```golang
func firstMissingPositive(nums []int) int {

	length, skip, has1 := len(nums), 0, false
	for i, v := range nums {
		if v == 1 {
			has1 = true
		}

		if v <= 0 || v > length { 
			nums[i] = 1
			skip ++
			continue
		}
	}

	if !has1 {
		return 1
	}

	for _, v := range nums {
		ind := abs(v) - 1; 
		if nums[ind] >= 0 {
			nums[ind] = - nums[ind]
		}
	}
 
	for i := 0; i < length - skip; i ++ {
		if nums[i] < 0 { 
			continue
		}
		return i + 1
	}

	return length - skip + 1
}
```

## 方法二: 桶排

其实也算不上, 由于遍历到 i 项时已经知道了其值对应位置的下标, 也就是 nums[i] - i (前提是 nums[i] 满足范围要求)

交换操作是收敛的, 可以无脑拍, 简称直接换就得了

```golang
func firstMissingPositive(nums []int) int { // 桶排
	length := len(nums)
	for i := 0; i < length; i ++ {
		vI := nums[i]
		if vI <= 0 || vI > length || nums[vI - 1] == vI  {
			continue
		}

		nums[vI - 1], nums[i] = vI, nums[vI - 1]
		i --
	}

	for i := 0; i < length; i ++ {
		if nums[i] != i + 1 {
			return i + 1
		}
	}

	return length + 1
}
```

虽然常数不同, 但是 O(n) 的方法怎么拍也都差不多