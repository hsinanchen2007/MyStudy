1. 所有的丑数都可以拆成之前的两个已知丑数相乘，那么就要找出这两个数来
2. 暴力的找法就是：每次尝试之前所有的相乘组合，取出值最小的那个，时间复杂度爆炸

优化思路：
1. 并不用每次都尝试所有组合，我们需要过滤掉不可能的组合
2. 已知2，3，5与已有丑数相乘时，数值增长速度是不一样的
3. 我们每次从三组新丑数中，挑选大于已知末尾丑数的最小值，来作为新的丑数
4. 乘3或者乘5的新丑数，如果某次未被选中放入数轴，那么肯定有某一刻会被放进去
5. 所以使用三个游标来确定已被放入数轴的新丑数最小值，每次仅需要对比这三个游标与2，3，5乘积即可
```
func nthUglyNumber(n int) int {
    return nthUglyNumberN(n, 2, 3, 5)
}

func nthUglyNumberN(n int, a int, b int, c int) int {
	nth := 1
	uglyList := make([]int, n)
	uglyList[0] = 1

	idx_a := 0
	idx_b := 0
	idx_c := 0

	for {
		if nth == n {
			return uglyList[n-1]
		}

		xa := uglyList[idx_a] * a
		xb := uglyList[idx_b] * b
		xc := uglyList[idx_c] * c

		uglyList[nth] = min3(xa, xb, xc)

		if uglyList[nth] == xa {
			idx_a++
		}
		if uglyList[nth] == xb {
			idx_b++
		}
		if uglyList[nth] == xc {
			idx_c++
		}

		nth++
	}
}


func min3(a, b, c int) int {
	return min2(min2(a, b), c)
}

func min2 (x, y int) int {
    if x < y {
        return x
    }
    return y
}


```
