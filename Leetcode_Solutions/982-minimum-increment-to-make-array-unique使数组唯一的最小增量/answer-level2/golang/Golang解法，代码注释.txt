### 解题思路
此处撰写解题思路

### 代码

```golang
func minIncrementForUnique(A []int) int {
    counts := [80000]int{}
	for _, a := range A {
		counts[a] += 1
	}
	result := 0  // 递增的次数
	remain := 0  // 剩余的需要安排坑位的数字个数
	for i := 0; i < 80000; i++ {
		count := counts[i]
		if count > 1 {
			result -= i * (count - 1) // 将多余的数字递减到0花的次数要减掉。
			remain += count - 1  // 又多了几个需要填坑的数字
		} else if count == 0 && remain > 0 {
			result += i // 选择一个数字安排到这个坑位要花i次递增（因为前面把所有数字减到0了）
			remain -= 1 // 少了一个需要填坑的数字
		}
	}

	return result
}
```