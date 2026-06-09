### 解题思路
学习了一下map的解法，其实这是一种**倒排索引**的思想，跟elastic道理相同，通过对value-->key 做索引实现快速找到目标数据。

其次为了追求算法的高性能，避免无用功，针对当前元素要么只跟前面的元素比较，要么只跟后面的元素比较，否则会出现，index1 跟 index2比较完后index2又跟index1比较的情况。



### 代码

```golang
func twoSum(nums []int, target int) []int {
	reverseIndex := make(map[int]int)
	for idx, val := range nums {
		needVal := target - val
		if idx2, ok := reverseIndex[needVal]; ok {
			if idx2!=idx {
				return []int{idx2,idx}
			}
		}
		reverseIndex[val] = idx
	}
	return []int{}
}
```

### 执行结果
执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :3.8 MB, 在所有 Go 提交中击败了48.91%的用户