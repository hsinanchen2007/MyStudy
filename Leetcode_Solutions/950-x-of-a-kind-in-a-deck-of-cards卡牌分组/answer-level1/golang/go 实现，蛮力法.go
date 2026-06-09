

![image.png](https://pic.leetcode-cn.com/49faad25f28c393c3f0e74a46edd4e2067952520cc3b1f34c55f2367270f1b64-image.png)

```go []
func hasGroupsSizeX(deck []int) bool {
	deckLen := len(deck)
	count := make([]int, 10000)
	for _, v := range deck {
		count[v]++
	}

	for i := 2; i <= deckLen; i++ {
		if deckLen%i == 0 {
			flag := true
			for _, v := range count {
				if v%i != 0 {
					flag = false
					break
				}
			}
			if flag {
				return true
			}
		}
	}

	return false
}

