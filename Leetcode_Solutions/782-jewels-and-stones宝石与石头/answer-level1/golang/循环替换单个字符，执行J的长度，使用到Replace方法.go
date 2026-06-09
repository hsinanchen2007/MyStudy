func numJewelsInStones(J string, S string) int {
	str := S
	for _,j := range []byte(J){
		str = strings.Replace(str,string(j),"",-1)
	}
	fmt.Println(str)
	return len(S) - len(str)
}