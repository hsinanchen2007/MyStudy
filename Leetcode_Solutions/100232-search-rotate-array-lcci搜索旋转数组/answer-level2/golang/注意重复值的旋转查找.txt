可以在查找之前先判断第一个元素是否为target，排除旋转的重复值如：[2,1,2,2]

```
  
func search(arr []int, target int) int {
	var left = 0
	var right = len(arr) - 1
	var index int
	if len(arr) < 1{
		return -1
	}
	if arr[0] == target{
		return 0
	}
	for left <= right{
		var mid = left + (right - left) / 2
		if arr[mid] == target{
			index = mid
			break
		} else if arr[left] > arr[mid]{
			if target > arr[mid] && target <= arr[right]{
				left = mid + 1
			}else {
				right = mid - 1
			}
		} else if arr[right] < arr[mid]{
			if target < arr[mid] && target >= arr[right] {
				right = mid - 1
			}else {
				left = mid + 1
			}
		} else if right == left{
			return -1
		} else {
			if target > arr[mid]{
				left = mid + 1
			}else {
				right = mid - 1
			}
		}
	}
	for index >=0 && arr[index] == target{
		index--
	}

	return index+1

}




```
