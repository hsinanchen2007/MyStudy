func checkValidString(s string) bool {
	return doCheckValidString(s,0,0,0)
}

func doCheckValidString(s string,index int,ln,rn int) bool {
	for i:=index;i<len(s);i++{
		if s[i] == '(' {
			ln++
		} else if s[i] == ')' {
			rn++
		}else {
			return doCheckValidString(s,i+1,ln+1,rn)||doCheckValidString(s,i+1,ln,rn+1)||doCheckValidString(s,i+1,ln,rn)
		}
		if ln<rn{
			return false
		}
		//fmt.Println("ln=",ln," rn=",rn," i=",i)
	}
	if ln==rn{
		return true
	}
	return false
}