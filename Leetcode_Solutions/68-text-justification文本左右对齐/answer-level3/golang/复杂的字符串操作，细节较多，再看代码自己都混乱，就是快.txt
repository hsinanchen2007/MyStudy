
0ms   2.2MB    击败100%用户


```
func fullJustify(words []string, maxWidth int) []string {

    s := 0
    lastLen := 0
    try := 0
    var r []string
    for index:=0;index<len(words);index++ {
        try = len(words[index]) + lastLen
            if  try > maxWidth {
                conWords(&words,&r,s,index-1,lastLen,maxWidth)
                lastLen = 0
                try = 0
                s = index
                index -= 1
            }else if try == maxWidth{
                conWords(&words,&r,s,index,try+1,maxWidth)
                lastLen = 0
                try = 0
                s = index + 1                
            }else {
                lastLen = try + 1
            }
        
        
    }
    if try > 0 && try <= maxWidth {
        conWords(&words,&r,s,len(words)-1,lastLen,maxWidth)
    }
    return r
    
}
func conWords(words *[]string ,r *[]string,start int ,end int,curLen int,maxLen int) {
    var w string
	n := end-start+1
	a := 0
	c := 0
	spaces :=a
    
    if end == len(*words)-1 {
        a = 1
    }else if n==1 {
        
    }else {
        a = (maxLen -curLen +n)/(n-1)
        c = (maxLen -curLen +n)%(n-1)
        spaces = a
    }
    
    i := start 
    for i=start ;i<end;i++ {
        w += (*words)[i]
        if c > 0 {
            spaces = a+ 1
            c -= 1
        }else {
            spaces = a
        }
        
        for j:=0;j<spaces;j++ {
            w += " "
        }
    }
    w += (*words)[end]
     
    //
    if ((end == len(*words)-1 || n == 1) && curLen <= maxLen) {
        for j:=0;j<maxLen-curLen+1;j++ {
            w += " "
        }
    }
    *r = append(*r,w)
}
```

