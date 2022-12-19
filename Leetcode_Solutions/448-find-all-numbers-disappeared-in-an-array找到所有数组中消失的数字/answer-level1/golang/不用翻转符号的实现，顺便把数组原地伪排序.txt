根据数组的特征（n个int，值范围在1到n之间）可知，如果正好每一个值都出现且只出现一次，那么满足：
for any given k in the range [0,n-1],
we have: nums[k] = k+1

所以得到此题一个解决思路：
步骤一：将数组排正序 （不完全排序，重复出现的数字会被放置在没有出现的数字的位置上）
例如，[4,3,2,7,8,2,3,1] 伪排序后变成 [1,2,3,4,**3,2**,7,8]
步骤二：挑出所有满足如下条件的 x ,即实际中没有出现的数字
 1. 1 <= x <= n
 2. nums[x-1] != x

因为排序中要一个int类型变量辅助，所以不能严格意义上认为不占用额外空间，但是空间复杂度仍旧为 O(1), 时间复杂度 O(n)

```
func findDisappearedNumbers(nums []int) []int {
	result := []int{}
	length := len(nums)
    //如果输入序列长度为0或者1，必然结果集为空
	if length == 0 || length == 1 {
		return result
	}
	i := 0
	var tmp int
    //排序循环
	for {
        //到达尾部，排序结束
		if i == length {
			break
		}
        //数字对位，跳过
		if nums[i] == i+1 {
			i++
			continue
		}
		tmp = nums[nums[i]-1]
        //如果目标位上已有对位数值，跳过
		if tmp == nums[i] {
			i++
			continue
		}
		nums[nums[i]-1] = nums[i]
		nums[i] = tmp
	}
    //遍历找出结果集
	for i = 0; i < length; i++ {
		if nums[i] != i+1 {
			result = append(result, i+1)
		}
	}
	return result
}
```
