func fibonacci() func() (int,int) {
	a,b := 1,0
	return func() (int,int) {
		a,b = b,a+b
		return a,b
	}
}

func fib(N int) int {
	if N == 0 {
		return 0
	}

	f := fibonacci()
	for i := 0; i < N-2 ; i++ {
		f()
	}
	a,b := f()
	return a+b
}