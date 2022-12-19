* 基本思路是，每次再前一次的基础上，动态的递增新的字母，省去了递归每次重复计算的成本
* 假如三个字母的字符有N个，四个字母的字符有M个，时间复杂度为 
* O(3^(N+1)/2 + 4^(M+1)/3)
> 感觉还有更好的办法，欢迎大家的指导

	func letterCombinations(digits string) []string {
		m := map[int32][]byte{
			50: {97, 98, 99},
			51: {100, 101, 102},
			52: {103, 104, 105},
			53: {106, 107, 108},
			54: {109, 110, 111},
			55: {112, 113, 114, 115},
			56: {116, 117, 118},
			57: {119, 120, 121, 122},
		}
		t := make([][]byte, 0)
		for _, v := range digits {
			if mb, ok := m[v]; ok {
				t = append(t, mb)
			}
		}
		var r [][]byte
		for i := 0; i < len(t); i++ {
			if len(r) > 0 {
				n := make([][]byte, len(r)*len(t[i]))
				for k, v := range r {
					l := len(t[i])
					for j := 0; j < l; j++ {
						for _,g := range v {
							n[k*l+j] = append(n[k*l+j],g)
						}
						n[k*l+j] = append(n[k*l+j], t[i][j])
					}
				}
				r = n
			} else {
				n := make([][]byte, len(t[i]))
				for j := 0; j < len(t[i]); j++ {
					n[j] = append(n[j], t[i][j])
				}
				r = n
			}
		}
		e := make([]string, len(r))
		for i, v := range r {
			e[i] = string(v)
		}
		return e
	}