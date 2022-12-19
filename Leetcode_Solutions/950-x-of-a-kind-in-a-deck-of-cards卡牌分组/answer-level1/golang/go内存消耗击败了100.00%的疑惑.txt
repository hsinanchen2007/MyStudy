### 解题思路

- 1、统计各数字出现次数

    使用map来统计，map的大小根据传入数据的大小来确定。另外经过反复多次测试发现，map的key会按照大小自动排序。

- 2、计算所有次数的最大公约数


> 疑惑：并没有发现代码哪里有刻意节约内存的地方，为什么击败了其它全部用户呢？连续提交了两次都是。

### 代码

```golang
func hasGroupsSizeX(deck []int) bool {
	size := len(deck)
	// 统计每个数字的数量
	deckMap := make(map[int]int, size)
	for i := 0; i < size; i++ {
		if n, ok := deckMap[deck[i]]; ok {
			deckMap[deck[i]] = n + 1
		} else {
			deckMap[deck[i]] = 1
		}
	}

	g := 0
	for _, count := range deckMap {
		if g = gcd(g, count); 1 == g {
			return false
		}
	}
	return g > 1
}

// 两个数的最大公约数
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

```