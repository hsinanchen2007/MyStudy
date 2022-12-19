![image.png](https://pic.leetcode-cn.com/f7847bc376a54eafe72fb1802f6f744bda5fe7f290af4ce94ad59834b9c150d3-image.png)

1. 解题前需要仔细读题，尤其是“i 和 j 的差的绝对值最大为 k”这句略坑
2. 暴力双层循环会超时
3. 借用map的key不会重复的特性实现，可以不用遍历完数组
4. 不借用内置函数
5. 代码如下：
```
func containsNearbyDuplicate(nums []int, k int) bool {
	var m = make(map[int]int)
	for i := 0; i < len(nums); i++ {
		if _, ok := m[nums[i]]; ok {
			t := 0
			if m[nums[i]] > i {
				t = m[nums[i]] - i
			} else {
				t = i - m[nums[i]]
			}
			if t <= k {
				return true
			} 
		}
		 m[nums[i]] = i
	}

	return false
}
```
