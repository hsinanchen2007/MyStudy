主要的思路是这样的：
1. arr1和arr2都先用快速排序排好，输出sorted1，sorted2。这个时间复杂度O(log(n)),空间O(n)
2. 由于arr2不可重复，所以可以用一个map将arr2中的value和它在arr1中对应的数字记录下来。空间O(n)
3. arr1和arr2排序后，采用双指针：
- 如果arr1的指针<arr2的，说明这个值只出现在arr1中，加入newElements，arr1指针向后移动
- 如果arr1的指针==arr2的，加入到刚才说的map里，key=arr2的value，v=arr1中的相同value的数组，arr1指针向后移动
- 如果arr1的指针>arr2的，说明arr2的当前数字已经比较完毕，arr2的指针向后移动

因为arr2中的每个元素都出现在arr1中，所以一定是arr2先跑完指针，那么arr1中剩下的部分直接加入newElements即可（反正排好序了)。

最后遍历原始的arr2，在map中找到对应的arr1中的数组，append起来，再加上newElements，即可得到答案。

看代码： (sortArray为快排，大佬们各自随意实现即可)

```
func relativeSortArray(arr1 []int, arr2 []int)(res []int) {
	pos2 := make(map[int][]int) // k=数，v=arr1中的数组
	sorted1 := sortArray(arr1)
	sorted2 := sortArray(arr2)
	i := 0 // 双指针
	j := 0
	var newEles []int
	for i<len(sorted2) && j<len(sorted1){
		if sorted1[j] < sorted2[i]{ // 小，说明1中为新元素
			newEles = append(newEles, sorted1[j])
			j++
		} else if sorted1[j] == sorted2[i] { // 相等，加入到map中
			pos2[sorted2[i]]  = append(pos2[sorted2[i]], sorted1[j]) 
			j++
		} else { // 说明到下一个数字了
			i++
		}
	}
	newEles = append(newEles, sorted1[j:]...) // 剩余的1中的一些数字，反正已经排好序了放在后面即可
	for i:=0; i<len(arr2); i++{
		res = append(res, pos2[arr2[i]]...)
	}
	res = append(res, newEles...)
	return
}

```
