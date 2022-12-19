### 解题思路
此处撰写解题思路

### 代码

```golang
func isAlienSorted(words []string, order string) bool {
	orderRune:=[]rune(order)
	orderMap:=make(map[rune]int)
	for i,v:=range orderRune{
		orderMap[v]=i
	}
	for i:=0;i< len(words)-1;i++{
		if !helpIsAlienSorted(words[i],words[i+1],orderMap){
			return false
		}
	}
	return true
}

func helpIsAlienSorted(a,b string,orderMap map[rune]int)bool{
	runeA:=[]rune(a)
	runeB:=[]rune(b)
	var N int
	if len(runeA)<= len(runeB){
		N= len(runeA)
	}else{
		N= len(runeB)
	}
	for i:=0;i<N;i++{
		if orderMap[runeA[i]]<orderMap[runeB[i]]{
			return true
		}else if orderMap[runeA[i]]>orderMap[runeB[i]]{
			return false
		}
	}
	if len(runeA)> len(runeB){
		return false
	}
	return true
}

```