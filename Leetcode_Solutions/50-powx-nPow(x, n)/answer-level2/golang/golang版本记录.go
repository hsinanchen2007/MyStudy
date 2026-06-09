func myPow(x float64, n int) float64 {
	/*
		pow(x^n)
			subproblem: subresult pow(x^n/2)
		merge:
			if n & 1 == 1 then subresult = subresult * subresult * x (奇数)
			else subresult = subresult * subresult
	*/
	// 处理复数的情况
	if n < 0 {
		n = -n
		return 1/fastPow(x, n)
	}
	return fastPow(x, n)
}

func fastPow(x float64, n int) float64 {
	if n == 0 {
		return 1
	}

	sub := fastPow(x, n/2)
	if n & 1 == 1 {
		sub = sub * sub * x
	} else {
		sub = sub * sub
	}
	return sub
}