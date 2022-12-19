```

func countPrimeSetBits(L int, R int) int {
	res := 0
	for i := L; i <= R; i++ {
		binStr := strconv.FormatInt(int64(i), 2)
		count := strings.Count(binStr, "1")
		if isPrime(count) {
			res++
		}
	}

	return res
}

func isPrime(value int) bool {
	if value <= 3 {
		return value >= 2
	}
	if value%2 == 0 || value%3 == 0 {
		return false
	}
	for i := 5; i*i <= value; i += 6 {
		if value%i == 0 || value%(i+2) == 0 {
			return false
		}
	}
	return true
}

```