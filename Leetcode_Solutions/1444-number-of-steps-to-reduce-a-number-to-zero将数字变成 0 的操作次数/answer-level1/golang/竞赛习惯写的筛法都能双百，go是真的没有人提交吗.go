//感觉用例很好过
func numberOfSteps (num int) int {
	var cache=make([]int,1000000)
	cache[1]=1
	cache[2]=2
	for i:=1;i<=1000000;i++ {
		if i*2 < 1000000 {
			if cache[i*2]==0 {
				cache[i*2] = cache[i] + 1
			}else {
				cache[i*2] = int(math.Min(float64(cache[i]+1), float64(cache[i*2])))
			}
		}
		if i < 1000000-1 {
			if cache[i+1]==0 {
				cache[i+1] = cache[i] + 1
			}else {
				cache[i+1] = int(math.Min(float64(cache[i]+1), float64(cache[i+1])))
			}
		}
	}
	return cache[num]
}