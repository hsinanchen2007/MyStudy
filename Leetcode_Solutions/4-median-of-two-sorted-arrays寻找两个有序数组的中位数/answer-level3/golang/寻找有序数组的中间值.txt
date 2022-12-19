### 解题思路
##### 1. 首先把两个数组合二为一
##### 2. 把两个int数组进行排序(题目已经假设为有序数组)
##### 3. 根据新数组的元素长度取出一个中间值 我们称之为 middleIndex
##### 4. 分析发现 如果数组长度为偶数，中间值则为中间两个元素之和的平均数，中间两值的对应索引分别为：middleIndex - 1, middleIndex
##### 5. 分析发现 如果数组长度为奇数，中间值则为最中间的那个元素

### 代码

```golang
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    newNums := append(nums1, nums2...)
	sort.Ints(newNums)
	middleIndex := len(newNums) / 2
	var result float64
	if len(newNums)%2 == 0 {
		index1, index2 := middleIndex-1, middleIndex
		result = (float64)(newNums[index1]+newNums[index2]) / 2
	} else {
		index := int(middleIndex)
		result = float64(newNums[index])
	}
    return result
}
```