```
func convert(s string, numRows int) string {
	if numRows == 1{
		return s
	}
	str := ""
	c := 2*numRows -2
	n := len(s)
	for i:=0;i < numRows;i++{
		for j:=0; j+i< n; j+= c{
			str += string(s[j+i])
			if i != 0 && i != numRows -1 && j+c -i < n{
				str += string(s[j+c -i])
			}
		}
	}
	return str
}
```
