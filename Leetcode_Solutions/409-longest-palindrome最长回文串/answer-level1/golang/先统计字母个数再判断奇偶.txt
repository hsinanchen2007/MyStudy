```
func longestPalindrome(s string) int {
 dict:=map[string]int{}
 a:=""
 for i:=0;i<len(s);i++{
     cur:=string(s[i])
     _,ok:=dict[cur]
     if ok{
         dict[cur]+=1
     }else{
         dict[cur]=1
         a+=cur
     }
 }
 ji:=0
  ou:=0
 jinum:=0
for j:=0;j<len(a);j++{
    curr:= dict[string(a[j])]
    if curr%2==1{
       ji+=curr-1
       jinum+=1
    }else{
        ou+=curr
    }
}
sum:=0 
if jinum>0{
sum=sum+ji+ou+1
}else{
    sum+=ou
}
return sum
}
```
