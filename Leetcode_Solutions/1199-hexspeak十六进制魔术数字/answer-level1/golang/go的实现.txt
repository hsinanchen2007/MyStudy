```
func toHexspeak(num string) string {
	ints, _ := strconv.Atoi(num)
	h := fmt.Sprintf("%x",ints)
	abs:= []byte(h)
	maps := map[byte]byte{
		'0':'O',
		'1':'I',
		'a':'A',
		'b':'B',
		'c':'C',
		'd':'D',
		'e':'E',
		'f':'F',
	}
	var ans string
	for _,v := range abs{
		_,ok := maps[v]
		if !ok {
			return  "ERROR"
		}
		ans += string(maps[v])
	}
	return ans
}
```
