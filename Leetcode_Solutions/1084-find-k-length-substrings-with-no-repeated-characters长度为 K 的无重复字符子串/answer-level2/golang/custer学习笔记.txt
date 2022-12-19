# 第一思路暴力解发
```go 
func numKLenSubstrNoRepeats(S string, K int) int {
	res := make([]string, 0)
	if len(S) < K {
		return 0
	}
	// 把K个长度的字符串拆分出现保存到切片中
	for i := range S {
		if i+K <= len(S) {
			res = append(res, S[i:i+K])
		}
	}
    // 分别对每K个长度的字符串进行查重处理，看是否存在重复字符
	count := 0
	for _, str := range res {
		for i := 0; i < len(str); i++ {
			for j := i + 1; j < len(str); j++ {
				if str[i] == str[j] {
					count++   // 有重复字符则计数加1
					goto Loop // 跳出循环到下一个字符串
				}
			}
		}
	Loop:
	}
	return len(res) - count // 返回所有长度为 K 且不含重复字符的子串
}
```
# 学习滑动窗口

https://leetcode-cn.com/u/caigogo

```go
func numKLenSubstrNoRepeats(S string, K int) int {
    count := make([]int, 26)
    ans := 0
    if K > len(S) {
        return 0
    }
    for i := 0; i < K; i++ {
        count[int(S[i] - 'a')]++
    }
    if valid(count) {
        ans++
    }
    for i := K; i < len(S); i++ {
        count[int(S[i] - 'a')]++
        count[int(S[i-K]-'a')]--
        if valid(count) {
            ans++
        }
    }
    return ans
}

func valid(count []int) bool {
    for i := 0; i < 26; i++ {
        if count[i] > 1 {
            return false
        }
    }
    return true
}
```