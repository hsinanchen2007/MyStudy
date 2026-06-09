```

func bitwiseComplement(N int) int {
	if N == 0 {
		return 1
	}

	l := 0
	n := N
	for n != 0 {
		n = n / 2
		l++
	}

	tmp := 0
	for i := 0; i < l; i++ {
		tmp += int(math.Pow(2, float64(i)))
	}
	bin := N ^ tmp
	
	return bin
}
```