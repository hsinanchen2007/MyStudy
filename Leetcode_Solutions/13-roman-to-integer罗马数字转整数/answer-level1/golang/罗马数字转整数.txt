### 解题思路
		//倒叙那到最后一位，例如：MCMXCIV 拿到V
		tmp := strMap[s[i]] //tmp = V = 5
		sign := 1           //标记 该加还是该减，IV(15):4，VI(51):6
		//第一轮V5和空0， 第二轮I1>V5,转负数
		if last > tmp {
			sign = -1
		}
		//6轮 ｜ 0+(1*5)			V			5
		//5轮 ｜ 5+(-1*1)		    IV			4
		//4轮 ｜ 4+(1*100)		    CIV			C 100	 +	IV 4
		//3轮 ｜ 104+(-1*10)		XCIV		XC 90    +  IV 4
		//2轮 ｜ 94+(1*1000)		MXCIV   	M 1000   +  XC 90    +  IV 4
		//1轮 ｜ 1094+(-1*100)	    CMXCIV  	CM 900	 +  XC 90    +  IV 4
		//0轮 ｜ 994+(1*1000)	    MCMXCIV		M 1000   +  CM 900	 +  XC 90    +  IV 4

### 代码

```golang
func romanToInt(s string) int {
	if s == "" {
		return 0
	}
	var (
		num  int
		last int
	)
	strMap := map[byte]int{'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
	for i := len(s) - 1; i >= 0; i-- {
		//倒叙那到最后一位，例如：MCMXCIV 拿到V
		tmp := strMap[s[i]] //tmp = V = 5
		sign := 1           //标记 该加还是该减，IV(15):4，VI(51):6
		//第一轮V5和空0， 第二轮I1>V5,转负数
		if last > tmp {
			sign = -1
		}
		//6轮 ｜ 0+(1*5)			V			5
		//5轮 ｜ 5+(-1*1)		IV			4
		//4轮 ｜ 4+(1*100)		CIV			C 100	 +	IV 4
		//3轮 ｜ 104+(-1*10)		XCIV		XC 90    +  IV 4
		//2轮 ｜ 94+(1*1000)		MXCIV   	M 1000   +  XC 90    +  IV 4
		//1轮 ｜ 1094+(-1*100)	CMXCIV  	CM 900	 +  XC 90    +  IV 4
		//0轮 ｜ 994+(1*1000)	MCMXCIV		M 1000   +  CM 900	 +  XC 90    +  IV 4
		num += sign * tmp
		last = tmp
	}
	return num
}
```