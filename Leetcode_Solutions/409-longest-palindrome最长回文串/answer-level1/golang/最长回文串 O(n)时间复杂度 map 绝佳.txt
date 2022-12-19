`func longestPalindrome(s string)(length int ){
    count := make(map[byte]int)
    odd := 0
    for i:=0;i<len(s);i++{
        count[s[i]]++
        if count[s[i]]%2 == 0{
            length+=2
            odd--
        }else{
            odd ++
        }
    }
    if odd >=1{
        length ++
    }
    return 
}`