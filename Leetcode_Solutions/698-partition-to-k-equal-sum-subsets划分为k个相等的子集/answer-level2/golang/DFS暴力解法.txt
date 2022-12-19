### 解题思路
前面的平均值处理就不说了，都能想到。设平均值为sum
先说一下toselect的参数含义
nums：题目输入，k：题目输入，次数   sum：序列之和（也就是平均值nums之和/k）    selected:bool型的slice，用于记录数字是否已选，cur：已选数字的和   pos：当前数字的索引，下面会有说明
1）从头选择一个没有使用过的数，假设下标是pos
2）从pos+1开始没有被使用过的数（这里有一个支减，由于我们是从最前面开始选择的，因此只需要从当前位置+1开始遍历，避免重复循环）
3）如果找到一个数，和前面已求得的数之和小于等于sum，将新找到的数设置为已选，继续往后遍历（防止重复选择），直到和等于sum
4）如果遍历过程中和超过了sum（支减），或者遍历完了还是找不到要选的数字，把前面已经选过的数字设置为未选，重复第一步1），从下一个没有使用过的数字重新开始选择遍历
5）如果前面3步找到了这样一个序列，则重复执行，找下一个序列（注意，因为前面已经选过的数字已经被设置为true了，因此不会被重复选择。但是选择失败的数字我们在4）重新设置成了未选，因此后面可以重复使用）

这里的关键：可能出现的情况
举例：[10,10,10,14,6,14,6,14,6],如果要选择3个30，我们从头开始遍历可能会出现，先选择了3个10，然后剩下的无法组成2个30
但是实际上10,14,6是可以组成30，是有解的，这种情况该怎么处理？

这里开始写的时候犯错了，每次选择了一个序列之后就直接返回了，导致前面虽然能拼凑出30，但是后面没法再拼出两个20.
解决办法：必须要选满3个30的时候，才真正才结束。通过递归，如果所有数都selected了，但是没有选满5个，for循环中的递归仍然返回false，for循环继续执行直到能选完3个30，或者遍历完所有可能，都没有解，从最外层的false返回




### 代码

```golang
func toselect(nums []int, k int, sum int, selected []bool, cur int, pos int) bool {
	if k == 0 {
		return true
	}
	if cur == sum {
		return toselect(nums, k-1, sum, selected, 0, 0)
	}
	for i := pos; i < len(nums); i++ {
		if selected[i] == true {
			continue
		}
		selected[i] = true
		if cur+nums[i] <= sum && toselect(nums, k, sum, selected, cur+nums[i], i+1) {
			return true
		}
		selected[i] = false
	}
	return false
}

func canPartitionKSubsets(nums []int, k int) bool {
	sum := 0
	for _, v := range nums {
		sum = sum+v
	}
	if sum%k != 0 {
		return false
	}
	sum = sum/k
	if nums[len(nums)-1] > sum {
		return false
	}
	selected := make([]bool, len(nums))
	return toselect(nums, k, sum, selected, 0, 0)
}
```