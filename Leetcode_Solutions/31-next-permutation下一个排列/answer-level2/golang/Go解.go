### 解题思路
![image.png](https://pic.leetcode-cn.com/129d043df67b41e7007dd3831942ca3dc25400bd07ca5b55b765b6b397467021-image.png)


### 代码

```golang
func nextPermutation(nums []int) {

	if len(nums) < 2 {
		return
	}

	l := len(nums) - 1
	var change bool

	for i := l; i > 0; i-- {
		if nums[i] > nums[i-1] {
			change = true
			for k := i; k <= l; k++ {
				if nums[i-1] >= nums[k] {
					nums[i-1], nums[k-1] = nums[k-1], nums[i-1]
					reversalArr(i, nums)
					break
				}

				if k == l {
					nums[i-1], nums[k] = nums[k], nums[i-1]
					reversalArr(i, nums)
				}
			}
			break
		}
	}
    
    if !change {
        reversalArr(0, nums)
    }
}

func reversalArr(n int, nums []int) {
	l := len(nums) - 1
	for {
		if n >= l {
			break
		}
		nums[n], nums[l] = nums[l], nums[n]
		n++
		l--
	}
}

```