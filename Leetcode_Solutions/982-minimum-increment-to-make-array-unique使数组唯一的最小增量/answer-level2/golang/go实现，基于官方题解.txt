
```golang
func minIncrementForUnique(A []int) int {
	arr := [40001]int{} 

    for i := 0; i < len(A); i++ {
		arr[A[i]] += 1
	}

	times := 0 // 记录替换次数
	t := 0 
	i := 0
	nums := 0 // 记录处理过的元素个数
	for ; nums < len(A); i++ {

		if arr[i] == 0 {
			if t > 0 { 
				// 该元素是当前未出现的最小元素，添加
				t--
				times += i
			}

			continue
		}
        
        nums += arr[i] // 记录

		for arr[i] > 1 { // 元素重复出现
			arr[i]-- 
			t++ // 先记录有重复出现的元素，但是先不寻找当前最小的未出现的元素
			times -= i 
		}

	}

	for t > 0 {
		times += i
		i++
		t--
	}

	return times
}
```