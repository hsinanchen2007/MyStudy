func romanToInt(s string) int {
    num := map[string]int{
        "I" : 1,
        "V" : 5,
        "X" : 10,
        "L" : 50,
        "C" : 100,
        "D" : 500,
        "M" : 1000,
        "IV" : 4,
        "IX" : 9,
        "XL" : 40,
        "XC" : 90,
        "CD" : 400,
        "CM" : 900,
    }

    var returnNum int 
    for i:=0;i<len(s)-1;i++ {
            if num[string(s[i])] >= num[string(s[i+1])] {
                returnNum = returnNum + num[string(s[i])]
            }else{
                returnNum = returnNum - num[string(s[i])]
            }
        }
        returnNum = returnNum + num[string(s[len(s)-1])] 
    
    return returnNum
}