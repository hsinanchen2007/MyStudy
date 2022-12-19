```
func isValid(s string) bool {
  if s==""{
      return true
  }
  if len(s)%2!=0{
      return false
  }
  
  m:=map[byte]byte{
      ')':'(',
      '}':'{',
      ']':'[',
  }

  list:=[]byte{s[0]}
  for i:=1;i<len(s);i++{
      x,has:=m[s[i]]
      if !has{ // 是左括号,进栈
          list=append(list,s[i])
          continue
      }

      // 是右括号，判断是否出栈
        z:=list[len(list)-1]
        if z==x{
            list=list[:len(list)-1]
        }else{
            return false
        }
      
  }
  return len(list)==0
}
```
