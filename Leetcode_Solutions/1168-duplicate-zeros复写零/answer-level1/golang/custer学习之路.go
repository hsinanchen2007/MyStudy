薄弱的知识点：切片与切片之间的赋值，为值的复制

```go
func duplicateZeros(arr []int) {
	ret := make([]int, len(arr))
	times := 0 // 0出现的次数

	for i, v := range arr {

		if i+times < len(arr) {
			if v == 0 {
				times++
				if i+times < len(arr) {
					arr[i+times] = 0
				} else {
					arr = append(arr, 0)
				}
			} else {
				if i+times < len(arr) {
					arr[i+times] = v
				} else {
					arr = append(arr, v)
				}
			}
		}
	}
	for i := 0; i < len(arr); i++ {
		arr[i] = ret[i]
	}
        // arr = ret 这样是错误的，一直没有想明白，又饶了很大的弯，写了第二遍才意思到
}
```

走了弯路才知道为啥错了，哎

```go
func duplicateZeros(arr []int) {
	times := 0 // 0出现的次数
    // 拷贝数据不能直接tmp:=arr，跳在这个坑里半天
	tmp := make([]int, 0)
	for _, v := range arr {
		tmp = append(tmp, v)
	}
    // 原数组清空，也在这里卡了半天不知道怎么回事
	for i := range arr {
		arr[i] = 0
	}
	for i, v := range tmp {
		if i+times < len(tmp) {
			if v == 0 {
				times++
				if i+times < len(tmp) {
					arr[i+times] = v
				} else {
					arr = append(arr, v)
				}
			} else {
				if i+times < len(tmp) {
					arr[i+times] = v
				} else {
					arr = append(arr, v)
				}
			}
		}
	}
	// fmt.Print(arr)
}
```

学习下[@大佬的写法](https://leetcode-cn.com/u/caigogo)

```go
func duplicateZeros(arr []int) {
	var ans []int
	for i := 0; i < len(arr); i++ {
		if arr[i] == 0 {
			ans = append(ans, 0)
			ans = append(ans, 0)
		} else {
			ans = append(ans, arr[i])
		}
	}
	for i:=0; i< len(arr);i++{
		arr[i]=ans[i]
	}
}
```