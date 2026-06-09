求和题目，两数相加的题目，最终是两个链表合并的题目
```
func addBinary(a string, b string) string {
    c := 0              //进位
    n := 0              
    var num []byte
    var lenA int = len(a)-1
    var lenB int = len(b)-1
    for lenA >=0 && lenB >=0 {
        n = (int(a[lenA]-'0'+ b[lenB]-'0')+ c)%2 
        num = append(num,byte(n+'0'))
        c = (int(a[lenA]-'0'+b[lenB]-'0' )+ c)/2
        lenA--
        lenB--
    }
    
    for lenA>=0{
        n = (int(a[lenA] - '0') + c)%2
        num = append(num,byte(n+'0'))
        c = (int(a[lenA] -'0') + c)/2
        lenA--
    }
    for lenB >=0{
        n = (int(b[lenB] - '0')+ c)%2
        num = append(num,byte(n+'0'))
        c = (int(b[lenB] -'0') + c)/2
        lenB--
    }
    if c != 0{
        num = append(num,byte(c+'0'))
    }

    for i:=0;i<len(num)/2;i++{
        num[i] ,num[len(num)-1-i] = num[len(num)-1-i],num[i]
    }
 
    return string(num)
}

```





