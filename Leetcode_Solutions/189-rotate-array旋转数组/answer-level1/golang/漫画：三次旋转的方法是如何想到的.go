本题关键之处（完整代码见文末）：

- 找到翻转的规律

![image.png](https://pic.leetcode-cn.com/332d36bbbb881a4617e834dfb73f909f8d583778862fe25843557d84b6df4f84-image.png)


```go []
func rotate(nums []int, k int) {
	reverse(nums)
	reverse(nums[:k%len(nums)])
	reverse(nums[k%len(nums):])
}

func reverse(arr []int) {
	for i := 0; i < len(arr)/2; i++ {
		arr[i], arr[len(arr)-i-1] = arr[len(arr)-i-1], arr[i]
	}
}
```
