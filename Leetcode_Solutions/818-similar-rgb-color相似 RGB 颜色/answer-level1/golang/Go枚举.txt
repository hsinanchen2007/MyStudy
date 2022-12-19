```

func similarity(hex1, hex2 int64) int  {
	ans := 0
	col1 := 0
	col2 := 0
	for i:=16;i >= 0;i-=8{
		switch i {
			case 16:
				col1 =  int(hex1) >> 16 % 256
				col2 =  int(hex2) >> 16 % 256
		case 8:
			col1 =   int(hex1) >> 8 % 256
			col2 =   int(hex2) >> 8 % 256
		case 0:
			col1 =   int(hex1) >> 0 % 256
			col2 =   int(hex2) >> 0 % 256
		}
		ans -= (col1 - col2) * (col1 - col2)
	}
	return  ans
}
func similarRGB(color string) string {
		hex1 ,_:= strconv.ParseInt(color[1:],16,32)
		ans := int64(0)
		for  r := 0; r < 16; r++{
			for g := 0; g < 16; g++{
				for b := 0; b < 16; b++{
					 hex2 := int64(17 * r * (1 << 16) + 17 * g * (1 << 8) + 17 * b)
					 if similarity(hex1, hex2) > similarity(hex1, ans){
						 ans = hex2
					 }
				}
			}

		}
		return  fmt.Sprintf("#%06x", ans)
}
```
