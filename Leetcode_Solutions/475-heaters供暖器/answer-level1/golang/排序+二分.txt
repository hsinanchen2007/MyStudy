排序+二分
```
func findRadius(houses []int, heaters []int) int {
    sort.Ints(houses)
	sort.Ints(heaters)
    max := 0
    for _,v:= range houses {
        if v >= heaters[len(heaters)-1] {
			if max < v-heaters[len(heaters)-1] {
				max = v - heaters[len(heaters)-1]
			}
			continue
		} else if v <= heaters[0] {
			if max < heaters[0]-v {
				max = heaters[0] - v
			}
			continue
		}
        
        left := 0
        right := len(heaters)-1
        mid := left + (right-left)/2
        for left <= right {
            mid = left + (right-left)/2
            if heaters[mid] >= v {
                if mid == 0 || heaters[mid-1] < v {
                    break
                }
                right = mid - 1
            }else {
                left = mid + 1
            }
        }
        l := 0
        if heaters[mid] == v {
            l = 0
        }else {
            if mid - 1 >= 0{
                l1 := v - heaters[mid-1]
                l2 := heaters[mid] - v
                if l1 >= l2 {
                    l = l2
                }else {
                    l = l1
                }
            }else {
                l = heaters[mid] - v
            }
        }
        
        if max < l {
            max = l
        }
    }
    return max
}
```
