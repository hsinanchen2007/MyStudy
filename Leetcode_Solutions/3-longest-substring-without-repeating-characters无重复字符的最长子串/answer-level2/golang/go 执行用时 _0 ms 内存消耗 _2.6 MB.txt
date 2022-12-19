### 解题思路
go解答，其中滑动窗口－数据解法
执行用时 :0 ms, 在所有 Go 提交中击败了100.00% 的用户
内存消耗 :2.6 MB, 在所有 Go 提交中击败了93.37%的用户

#### 暴力解法:
```golang
func lengthOfLongestSubstring(s string) int {
    count := len(s)
	var max int
	for i := 0; i < count; i++ {
		if max >= count-i {
			break
		}
		has := make(map[byte]int, count-i)
		hasCount := 1
		has[s[i]] = i
		if max < 1 {
			max = 1
		}

		for j := i + 1; j < count; j++ {
			if _, ok := has[s[j]]; ok {
				if max < hasCount {
					max = hasCount
				}
				break
			} else {
				if j == count-1 {
					if max < hasCount+1 {
						max = hasCount + 1
					}
				} else {
					has[s[j]] = j
					hasCount++
				}
			}
		}
	}
	return max
}
```

#### 滑动窗口--map
```goalng
func lengthOfLongestSubstring(s string) int {
    count := len(s)
	max := 0
	i := 0
	j := 0
	has := make(map[byte]int, count)
	for ; j < count; j++ {
		if max >= count-i {
			break
		}
		k, ok := has[s[j]]
		if ok {
			if i < k+1 {
				i = k + 1
			}
		}
		if max < j-i+1 {
			max = j - i + 1
		}
		has[s[j]] = j
	}
	return max
}
```

#### 滑动窗口--数组

```golang
func lengthOfLongestSubstring(s string) int {
    count := len(s)
	max := 0
	i := 0
	j := 0
	var has [128]int
	for ; j < count; j++ {
		if max >= count-i {
			break
		}
		k := has[s[j]]
		if k != 0 {
			if i < k {
				i = k
			}
		}
		if max < j-i+1 {
			max = j - i + 1
		}
		has[s[j]] = j + 1
	}
	return max
}
```