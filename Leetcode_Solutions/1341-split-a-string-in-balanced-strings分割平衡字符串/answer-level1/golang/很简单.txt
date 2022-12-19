func balancedStringSplit(s string) int {
	sum:=0
	num:=0
	c := strings.Split(s, "")
	for i:=0;i<len(c) ;i++  {
		if c[i]=="L"{
			sum--
		}else{
			sum++
		}
		if sum==0 {
			num++
		}
	}
	return num
}