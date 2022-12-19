### 解题思路
![image.png](https://pic.leetcode-cn.com/87ce70bd81067648f0b6a85f7206bf3a5d2b7b99227fc20d9c6fc4d60a52a4d5-image.png)

### 代码

```golang
var result [][]int

func combinationSum(candidates []int, target int) [][]int {

	if len(candidates) == 0 {
		return nil
	}

    result = make([][]int, 0, len(candidates))

	nums := make([]int, 0, len(candidates))

    //排序
    sort.Ints(candidates)

	arrangeSum(candidates, nums, target, 0)

	return result
}

func arrangeSum(candidates, nums []int, target int, sum int) {

	//判断终止条件
	if sum >= target {
		return
	}

	for _, v := range candidates {
        if (len(nums)) > 0 && (nums[len(nums)-1] > v) {
            continue
        }
		nums = append(nums, v)
        sum += v

		arrangeSum(candidates, nums, target, sum)

		if sum == target {
            temp := make([]int, len(nums))
            copy(temp, nums)
            result = append(result, temp)
		}

		sum -= v
		nums = nums[:len(nums)-1]
	}
}
```