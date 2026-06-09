```


func powerfulIntegers(x int, y int, bound int) []int {
	var res1 = make(map[int]byte)
	var res2 []int
	var pow = func() func(int) int {
		var res int
		return func(x int) int {
			if res == 0 || x == 1 {
				res = 1
			} else {
				res *= x
			}
			return res
		}
	}
	var tempx, tempy []int
	powx := pow()
	powy := pow()
	for data := 0; ; {
		data = powx(x)
		if x == 1 {
			tempx = append(tempx, data)
			break
		}
		if data <= bound {
			tempx = append(tempx, data)
		} else {
			break
		}
	}
	for data := 0; ; {
		data = powy(y)
		if y == 1 {
			tempy = append(tempy, data)
			break
		}
		if data <= bound {
			tempy = append(tempy, data)
		} else {
			break
		}
	}
	for _, v1 := range tempx {
		for _, v2 := range tempy {
			if v1+v2 <= bound {
				res1[v1+v2] = 0
			}
		}
	}
	for v := range res1 {
		res2 = append(res2, v)
	}
	return res2

}


```

![BaiduShurufa_2019-5-22_9-30-13.png](https://pic.leetcode-cn.com/60f8948ad6aa5e2f6a0f6f251923e00d6353baa1e21dae0899d9e69f097f949c-BaiduShurufa_2019-5-22_9-30-13.png)