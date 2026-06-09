### 解题思路
此处撰写解题思路

### 代码

```golang

func maxSumOfThreeSubarrays(nums []int, k int) []int {
	times := 3
	if times * k > len(nums) {
		panic("nums length is wrong")
	}
	var tmp_array []int
	for i := 0 ;i<len(nums) - k + 1 ;i++ {
		var tmp_value int
		tmp_k := k
		for {
			if tmp_k == 0 {
				break
			}
			tmp_value += nums[i+tmp_k-1]
			tmp_k--
		}
		tmp_array = append(tmp_array, tmp_value)
	}
	//使用三次for查找，时间复杂度不允许
	// tmp_result := -1
	// result := []int{}
	// for j:=0 ;j<len(tmp_array)-k-k ;j++ {
	// 	for m:=j+k ;m<len(tmp_array)-k; m++ {
	// 		for n:=m+k ;n<len(tmp_array); n++ {
	// 			sum_tmp := tmp_array[j]+tmp_array[m]+tmp_array[n]
	// 			if sum_tmp > tmp_result{
	// 				tmp_result = sum_tmp
	// 				result = []int{j,m,n}
	// 			}
	// 		}
	// 	}
	// }
	//时间复杂度不允许，空间换时间

	//tmp_array遍历，得出左边部分最大的对应的下标
	left_tmp := tmp_array[0]
	left_value := []int{0}
	for left:=1 ;left<len(tmp_array) ;left++ {
		if tmp_array[left]>left_tmp {
			left_value = append(left_value,left)
			left_tmp = tmp_array[left]
		} else {
			left_value = append(left_value,left_value[left-1])
		}
	}
	//右边的，同上
	right_tmp := tmp_array[len(tmp_array)-1]
	right_value := []int{len(tmp_array)-1}
	for right:=len(tmp_array)-2 ;right>=0 ;right-- {
		if tmp_array[right]>=right_tmp {
			x := []int{right}
			right_value = append(x,right_value...)
			right_tmp = tmp_array[right]
		} else {
			right_value = append([]int{right_value[0]},right_value...)
		}
	}
	//定义
	result := []int{0,k,2*k}
	sum_max := 0
	//遍历比较每个值
	for m:=k ;m<len(tmp_array)-k ;m++ {
		sum_t := tmp_array[left_value[m-k]]+tmp_array[m]+tmp_array[right_value[m+k]]
		if sum_t>sum_max {
			sum_max = sum_t
			result = []int{left_value[m-k],m,right_value[m+k]}
		}
	}

	return result
}
```