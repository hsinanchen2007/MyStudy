```
func isUnique(astr string) bool {
  a:=0
  for _,b:=range astr{
      c:=1<< (int(b)-int('a'))
     if a&c!=0{
         return false
     }
     a|=c
}
return true
}
```
