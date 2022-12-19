本题主要的目的是找到山峰

首先我们考虑一个idx要成为山峰的必要条件： 左右两边的值都要小于当前的值，类似的可以得到左右峰的条件
- 山顶： mountain[idx-1] < moutain[idx] &&  mountain[idx+1] < moutain[idx]。
- 左峰： mountain[idx-1] < moutain[idx] &&  mountain[idx] < moutain[idx+1], 递增
- 右峰： mountain[idx-1] > moutain[idx] &&  mountain[idx] > moutain[idx+1], 递减


根据上面的条件，我们可以很简单的通过二分查找最快的找到山峰。
- mid在左峰，山顶还在右侧，low = mid + 1。 如果在左锋找到target，可以直接返回，没有必要再去照山顶了。
- mid在右峰，山顶还在左侧，high = mid - 1。
- 特别的，如果mid = 0 或者 mid = len(mountain), 需要忘两边顺移，保证3个值不同。


找到山峰后就是简单二分查找，先找左再找右，就不详述了
```
func findInMountainArray(target int, mountainArr *MountainArray) int {
	length := mountainArr.length()
	low, high := 0, length - 1
	highest := -1
	for low < high {
		mid := low + (high - low)/2
		if mid == 0 {
			mid += 1
			high += 1
		}
		if mid == length - 1 {
			low -= 1
			mid -= 1
		}
		l, m, h :=  mountainArr.get(mid-1),  mountainArr.get(mid),  mountainArr.get(mid+1)
		if m > l && m < h { // 山顶还在右侧
			low = mid + 1
			if l == target {
				return mid - 1
			}
			if m == target {
				return mid
			}
			if h == target {
				return mid + 1
			}
		} else if m < l && m > h { // 山顶还在左侧
			high = mid -1
		} else {
			highest = mid
			if m == target {
				return mid
			}
			break
		}
	}
    if highest == -1 {
        highest = low
    }
	low, high = 0, highest
	for low <= high {
		mid := low + (high - low)/2
		m :=  mountainArr.get(mid)
		if target == m {
			return mid
		} else if target > m {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
    
	low, high = highest, length - 1
	for low <= high {
		mid := low + (high - low)/2
		m :=  mountainArr.get(mid)
		if target == m {
			return mid
		} else if target < m {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
	return -1
}
```
