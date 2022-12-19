func mySqrt(x int) int {
	result :=math.Sqrt(float64(x))
	k,_ := math.Modf(result)
	return int(k)
}