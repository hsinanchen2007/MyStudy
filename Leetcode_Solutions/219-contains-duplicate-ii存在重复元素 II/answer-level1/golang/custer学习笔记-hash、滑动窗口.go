# 思考

学习自[画解算法](https://leetcode-cn.com/problems/contains-duplicate-ii/solution/hua-jie-suan-fa-219-cun-zai-zhong-fu-yuan-su-ii-by/)

- 维护一个哈希表，里面始终最多包含k个元素，当出现重复值时则说明在k距离内存在重复元素
- 每次遍历一个元素则将其加入哈希表中，如果哈希表的大小大于k，则移除最前面的数字
- 时间复杂度：O(n)，n为数组长度

# Go实现

```go
// 滑动窗口+查找表 Time: O(n), Space: O(k)
func containsNearbyDuplicate(nums []int, k int) bool {
   record := make(map[int]int) // 记录窗口的查找表
   for i := 0; i < len(nums); i++ {
      if _, ok := record[nums[i]]; ok {
         return true // 在窗口中找到这个元素
      }
      // 否则说明新的数与窗口中任意数都不重复
      record[nums[i]] = i // 将新的数添加到窗口中
      // 判断这个窗口有多大,保持record中最多有k个元素
      if len(record) == k+1 {
         // 删除这个窗口最左侧的数据
         delete(record, nums[i-k])
      }
   }
   return false // 循环结束后没有返回true即没有找到满足条件
}
```

# 优化代码
[学习自ElliotXX](https://leetcode-cn.com/problems/contains-duplicate-ii/solution/24msgo-shi-xian-by-elliotxx/)

```go
func containsNearbyDuplicate(nums []int, k int) bool {
	hash := make(map[int]int)
	for i, x := range nums {
		if j, ok := hash[x]; ok && i-j < k {
			return true
		}
		hash[x] = i
	}
	return false
}
```