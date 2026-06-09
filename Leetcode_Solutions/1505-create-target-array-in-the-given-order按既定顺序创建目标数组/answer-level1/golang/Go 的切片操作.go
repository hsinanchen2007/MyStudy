### 代码

```golang
package main

func createTargetArray(nums []int, index []int) []int {
	var res = make([]int, len(nums))
	for k, i := range index {
		copy(res[i+1:], res[i:]) //Go 圣经里讲的，插入应该怎么插，就这么插，纠结不能用函数的，当然也可以循环移动
		res[i] = nums[k] //插！
	}
	return res
}
```

[Go版本 Github](https://github.com/temporaries/leetcode)
