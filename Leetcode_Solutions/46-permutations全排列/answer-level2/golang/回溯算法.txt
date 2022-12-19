### 解题思路
此处撰写解题思路

### 代码

```golang
var result [][]int

func permute(nums []int) [][]int {

    result = make([][]int, 0, 2*len(nums))
    
    if len(nums) == 1 {
		result = append(result, nums)
		return result
	}

	arr := make([]int, 0, len(nums))

	arrange(nums, arr)

	return result
}

func arrange(nums []int, arr []int) {

	if len(nums) == 0 {
		return
	}

	for k, v := range nums {

		arr = append(arr, v)

		newArr := make([]int, len(nums)-1)

		copy(newArr[:k], nums[:k])

		if k < len(nums)-1 {
			copy(newArr[k:], nums[k+1:])
		}

		arrange(newArr, arr)

        if len(arr) == cap(arr) {
            path := make([]int, len(arr))
            copy(path, arr)
            result = append(result, path)
        }

		arr = arr[:len(arr)-1]
	}
}
```