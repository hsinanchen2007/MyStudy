**使用切片自动化处理**

- 官方使用的俩字方法，第一种覆盖值，还是优化后的值交换，都涉及到值额外的些许空间拷贝
- 这里使用另外一种方法，用go自带的slice切片，避免空间值拷贝。

1. 官方值拷贝交换

```
func removeElement1(nums []int, val int) int {
	length := len(nums)
	for i:=0;i<length;{
		if nums[i] == val {
			nums[i] = nums[length-1]
			length--
		}else{
			i++
		}
	}
	return length
}
```
执行结果:
![image.png](https://pic.leetcode-cn.com/06cf981f8ed429efa5515cbcfbdb5dd74d2b8b3354e458769d9101d0cca9e1ce-image.png)


2. 使用slice切片

 
```
func removeElement(nums []int, val int) int {
	sort.Ints(nums)
	startIdx := -1
	endIdx := -1
	for i:=0;i<len(nums);i++ {
		if nums[i] == val {
			startIdx = i
			for j:=i+1;j<len(nums);j++ {
				if nums[j] != val {
					endIdx = j
					break
				}
			}
			break;
		}
	}
	if startIdx != -1 && endIdx == -1 {
		nums = append(nums[:startIdx])
	}else if startIdx != -1 && endIdx != -1{
		nums = append(nums[:startIdx], nums[endIdx:]...)
	}
	return len(nums)
}
```
执行结果：
![image.png](https://pic.leetcode-cn.com/9c4e4b75311cf36ecf9795707ddf08810ed716ecddb13761598b6e9fec10e154-image.png)
