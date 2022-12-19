首先做明白题意其实是想求出最长的值连续为1的长度
我们可以先处理int的切片，将收尾两端默认为0
尾部的处理是append一个0
头部可以默认index从 -1 开始
解法如下

```
func findMaxConsecutiveOnes(nums []int) (max int) {
	index := -1
	nums = append(nums,0)
	for i, v := range nums{
		if v == 0{
			if (i - index - 1) > max{
				max = i - index - 1
			}
			index = i
		}
	}
	return
}
```