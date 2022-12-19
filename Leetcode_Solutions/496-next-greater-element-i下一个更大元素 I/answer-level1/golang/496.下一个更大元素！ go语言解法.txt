### 解题思路

把遍历nums2，把其中每个数比其大的第一个数找出来，存在哈希表中，在遍历nums1，对应着哈希表来向结果切片里添加数据即可，hash表没有的添加-1。

### 代码

```golang
func nextGreaterElement(nums1 []int, nums2 []int) []int {
		hash := make(map[int]int)
		for i := 0;i < len(nums2);i++ {
			for j := i + 1;j < len(nums2);j++ {
				if nums2[j] > nums2[i] {
					hash[nums2[i]] = nums2[j]
					break
				}
			}
		}
		res := make([]int,len(nums1))
		for i,j := range nums1 {
			if _,ok := hash[j];!ok {
				res[i] = -1
			}else {
				res[i] = hash[j]
			}
		}
		return res
}
```