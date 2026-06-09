### 代码

```golang
func removeElement(nums []int, val int) int {
    index := 0
	for _, v := range nums {
		if v == val {
			continue
		}
		nums[index] = v
		index++
	}
	return index
}
```
### 执行结果
![image.png](https://pic.leetcode-cn.com/4064706737d96f2c2ad19a269e4986b30bdaf67036193f41f8321c4864afb682-image.png)
