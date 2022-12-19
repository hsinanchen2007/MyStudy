思路：
两个切片：window []int 保存当前窗口中对应值的nums的索引，且window中始终保持元素值对应的nums元素值单调递减
         res []int 保存结果值，每次从window队列头部去除索引并将对应nums的元素值加入res
i表示nums中从0开始的索引，当前对应的nums元素值比window中对应值都大时， window中值可清空，因为窗口的最大值必然是i所对应的值v。
window中的所有值均在k窗口中，左侧值要及时清空。
时间复杂度为: O(n)
```
// window中当前添加到队列尾的值为k，则前面比k小的都可以删除了，最大值不会在前面出现了，若是k小则加入到队列尾
// window中存放nums中元素索引，其对应nums值为单调递减
func maxSlidingWindow(nums []int, k int) []int {
	if nums == nil {
		return []int{}
	}
	window, res := []int{}, []int{}
	for i, v := range nums {
		// window头部元素被排除窗口
		if len(window) > 0 && window[0] <= i-k {
			window = window[1:]
		}
		// 若v比window中末尾索引对应值小跳过
		// 提出window中缩影对应值比v小的，保持window中元素索引对应值单调递减
		for len(window) > 0 && v >= nums[window[len(window)-1]] {
			window = window[:len(window)-1]
		}
		window = append(window, i) // 统一添加
		if i >= k-1 {
			res = append(res, nums[window[0]]) //window中最左侧值为当前窗口最大值，加入到队列中去
		}
	}

	return res
}

```