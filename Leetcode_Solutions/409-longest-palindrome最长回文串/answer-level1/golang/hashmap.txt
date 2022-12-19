### 解题思路
hashmap计数

### 代码

```golang
func longestPalindrome(s string) int {
	kv := map[byte]int{}

	for i := 0; i < len(s); i++ {
		kv[s[i]]++
	}

	count := 0
	for key, value := range kv {
		if value%2 == 0 {
			count += value
			kv[key] = 0
		}
		if value%2 == 1 && value > 2 {
			count += value - 1
			kv[key] = 1
		}
	}

	for _, value := range kv {
		if value == 1 {
			count++
			break
		}
	}

	return count
}
```