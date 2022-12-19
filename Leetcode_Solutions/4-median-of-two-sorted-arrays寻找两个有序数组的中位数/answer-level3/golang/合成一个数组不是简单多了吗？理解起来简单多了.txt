```
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    nums1 = append(nums1, nums2...)
    lenn := len(nums1)
    quickSort(nums1, 0, lenn-1)
    var res float64
    if(lenn%2 == 0){
        res = (float64(nums1[lenn/2 -1]) + float64(nums1[lenn/2]))/2
    }else{
        res = float64(nums1[lenn/2])
    }
    return res
}
func swap(arr []int, i, j int) {
	arr[i], arr[j] = arr[j], arr[i]
}

func partition(arr []int, left, right, key int) []int { // 划分
	less := left - 1  // 小于区
	more := right + 1 // 大于区
	index := left     // 下标
	for index < more {
		if arr[index] < key { // 小于划分值，就放到小于区
			swap(arr, less+1, index)
			less++  // 扩大小于区
			index++ // 比较下一个值
		} else if arr[index] > key { // 大于划分值，就放到大于区
			swap(arr, more-1, index)
			more-- // 扩大大于区；索引位置不变（因为当前值已经改变，需要再次比较）
		} else {
			index++ // 相同时，继续比较下一个
		}
	}
	// 返回等于区的位置
	return []int{less + 1, more - 1}
}

func quickSort(arr []int, left, right int) {
	if arr == nil || len(arr) < 2 {
		return
	}

	if left < right {
		part := partition(arr, left, right, arr[right]) //将数组最右边的值作为划分值
		quickSort(arr, left, part[0]-1)
		quickSort(arr, part[1]+1, right)
	}
}
```
![image.png](https://pic.leetcode-cn.com/e0ed5ca45e96ff301dd0679f36a8c6fdbc910ae218e359aa3112ea70982861b0-image.png)

