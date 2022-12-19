临时抱佛脚，看了一下课程，每一个石头可以选择放进背包，也可以选择不放心背包，不放背包的时候，处理第i个石头的时候，每种背包情况下包的总重量都是上一个石头的当前背包情况的总重量，当放进背包的时候，当前背包容量情况下上一个石头的总重量+当前石头的重量，既是当前石头的总重量，需要放到s[i][j+stones[i]]情况下去
```
func lastStoneWeightII(stones []int) int {
	sum := 0
	for _, v := range stones {
		sum += v
	}

	taget := sum / 2
	s := make([][]int, len(stones))
	for idx, _ := range s {
		s[idx] = make([]int, taget+1)
	}
	s[0][stones[0]] = stones[0]
	for i := 1; i < len(stones); i++ {
		for j:=0; j<=taget;j++  {	//不加
			s[i][j] = s[i-1][j]
		}
		for j := 0; j <= taget-stones[i]; j++ {
			if stones[i] <= taget {
				w := s[i-1][j] + stones[i]
				if w < s[i][j+stones[i]]{
					w = s[i][j+stones[i]]
				}
				s[i][j+stones[i]] = w
			}
		}
	}
	max := 0;
	for _, v := range s {
		for _, v1 := range v {
			if v1 > max {
				max = v1
			}
		}
	}
	return sum - 2*max
}
```
