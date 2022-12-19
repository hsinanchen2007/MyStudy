时间复杂度： O(n) 空间复杂度： O(1)
```
func reverseOnlyLetters(S string) string {
  strBytes := []byte(S)
	i:= 0
	j:= len(strBytes)-1
	for i < j{
		ii := strBytes[i]
		jj := strBytes[j]
		if !isZm(ii){
			i++
			continue
		}
		if !isZm(jj){
			j--
			continue
		}
		strBytes[i] = jj
		strBytes[j] = ii
		i++
		j--
	}
  return string(strBytes)
}
```
