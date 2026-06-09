### 解题思路
第一次选最多的插入2个（除非少于2个），然后根据最后一个字符x：
1）从剩下较多的字符，若干剩下的数量之和小于等于字符x剩下的一半，插入的数量为1，否则为2
2）停止条件：剩下的字符数量为0

### 代码

```golang
var ans []byte
func longestDiverseString(a int, b int, c int) string {
	if a+b+c == 0 {
		return ""
	}
	ans = ans[:0]
	cnts := []int{a, b, c}

	maxIdx := maxIdx(cnts)
	AddToString(cnts, maxIdx, 2)
	//fmt.Println(cnts, string(ans))

	loopFlg := true
	addNums := 0
	for cnts[0]+cnts[1]+cnts[2] > 0  && loopFlg{
		switch ans[len(ans)-1] {
			case 'a':
				//fmt.Println("case a")
				if cnts[1]+cnts[2] == 0 {
					loopFlg = false
					break
				}
				addNums =2
			    if cnts[1]+cnts[2] <= (cnts[0]+2)/2 {
					addNums = 1
				}
				if cnts[1] >= cnts[2] {
					AddToString(cnts, 1, addNums)
				}else {
					AddToString(cnts, 2, addNums)
				}
				//fmt.Println("after a ---", cnts, string(ans))
			case 'b':
				//fmt.Println("case b")
				if cnts[0]+cnts[2] == 0 {
					loopFlg = false
					break
				}
				addNums =2
				if cnts[0]+cnts[2] <= (cnts[1]+2)/2 {
					addNums = 1
				}
				if cnts[0] >= cnts[2] {
					AddToString(cnts, 0,  addNums)
				}else {
					AddToString(cnts, 2, addNums)
				}
				//fmt.Println("after b ---", cnts, string(ans))
			case 'c':
				//fmt.Println("case c", cnts)
				if cnts[0]+cnts[1] == 0 {
					loopFlg = false
					break
				}
				addNums =2
				if cnts[0]+cnts[1] <= (cnts[2]+2)/2 {
					addNums = 1
				}
				if cnts[0] >= cnts[1] {
					AddToString(cnts, 0, addNums)
				}else {
					AddToString(cnts, 1, addNums)
				}
				//fmt.Println("after c ---", cnts, string(ans))
			}
	}
	return string(ans)
}

func AddToString(cnts []int, maxIdx, n int)  {
	ans = append(ans, byte('a'+maxIdx))
	if cnts[maxIdx] >= 2 && n == 2 {
		ans = append(ans, byte('a'+maxIdx))
		cnts[maxIdx]--
	}
	cnts[maxIdx]--
}

func maxIdx(cnts []int) int {
	maxIdx := 0
	if cnts[1] > cnts[maxIdx] {
		maxIdx = 1
	}
	if cnts[2] > cnts[maxIdx] {
		maxIdx = 2
	}
	return maxIdx
}

```