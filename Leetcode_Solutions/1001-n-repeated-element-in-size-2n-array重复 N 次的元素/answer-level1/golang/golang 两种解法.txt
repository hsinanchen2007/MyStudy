### 解题思路

思路如注释所示


### 参考代码

```go
// 有一半的数是重复的，考虑最分散，即相间分布的情况，也会有连续三个数中有两个数是相同的
func repeatedNTimes(A []int) int {
	length := len(A)
	for i:=0;i<length-2;i++ {
		if A[i] == A[i+1] || A[i] == A[i+2] {
			return A[i]
		}
	}

	return A[length-1]
}

//建立hashmap然后遍历的过程中看哪个数出现的次数超过1
func repeatedNTimes(A []int) int {
	var mp [10001]int
	for _,value := range A {
		mp[value]++
		if mp[value] > 1 {
			return value
		}
	}
	return -1
}

```
**更多题解可以在我的[github](https://github.com/LZH139/leetcode_Go)上看到，每天都在持续更新，觉得还不错的话，记得点个小星星哈，谢谢啦**


