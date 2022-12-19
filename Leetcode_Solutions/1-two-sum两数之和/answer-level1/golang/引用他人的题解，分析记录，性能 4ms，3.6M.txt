
```
func twoSum(nums []int, target int) []int {
	length := len(nums)
	m := make(map[int]int,length-1)
	for i := 0;i< length;i++{
		if v,ok := m[nums[i]];ok{
			return []int{v, i}
		}
		m[target-nums[i]] = i
	}
	return []int{}
}

作者：lhlyu
链接：https://leetcode-cn.com/problems/two-sum/solution/zhong-jie-4ms36m-by-lhlyu/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

用于记录，在题解里看到了这个版本，想法确实很妙。这种方法，将所有 *target* 需要的差值存储在 map 里，如果 nums 中的元素在 map 里存在，那么就正好匹配，最差的情况也是遍历一遍 nums。
