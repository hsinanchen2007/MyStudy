内存为2M，执行0s
func numJewelsInStones(J string, S string) int {
    var sum int
    for i:=0;i<len(S);i++{
        if strings.Contains(J,string(S[i])){
            sum++
        }
    }
    return sum
}