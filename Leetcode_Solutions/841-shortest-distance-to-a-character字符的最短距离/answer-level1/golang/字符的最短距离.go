### 解题思路
此处撰写解题思路
主要是先把C在S中每个位置记录下来，后面遍历S进行判断长短即可

### 代码

```golang
func shortestToChar(S string, C byte) []int {
     a := make([]int,0)
    s := make([]int,len(S))
    for k,v := range S {
    	if (byte(v) == C) {
			a = append(a, k)
		}
	}

    for k,_ := range S {
		for k1,v1 := range a   {
			if (v1-k == 0) {
				s[k] = 0
				break
			}
			if (k1 == 0 && k-v1>0) {
				s[k] =  k-v1
			}

			if (k1 == 0 && k-v1<0) {
				s[k] =  v1-k
			}

			if (k1!=0 && k-v1>0 && (k-v1) < s[k]) {
				s[k] = k-v1
			}

			if (k1!=0 && k-v1<0 && (v1-k) < s[k]) {
				s[k] = v1-k
			}

		}
	}

    return s
}
```