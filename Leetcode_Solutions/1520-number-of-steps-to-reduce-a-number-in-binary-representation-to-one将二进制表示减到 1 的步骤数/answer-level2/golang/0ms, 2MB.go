### 解题思路

1. 操作字符串模拟过程

1 <= s.length <= 500
转int, 是不行的 

### 代码

```golang
func numSteps(s string) int {
    
    str := []byte(s)
    
    length := len(str)-1
    for  i:=0; i < len(str)/2; i++ {
        str[i], str[length-i] = str[length-i], str[i]
    }
    
    var res int 
    for !(len(str) == 1 && str[0] == '1' ){
        if str[0] == '1' {
            str = helper(str)
        } else {
            str = str[1:]
        }
        
        res++
    }
    
    
    return res 
}
// + 1
func helper(str []byte) []byte {
    str = append(str, '0')
    
    jin := '1'
    i := 0
    for  jin == '1' {
        if str[i] == '1' {
            str[i] = '0'
            jin = '1'
        }else {
            str[i] = '1' 
            jin = '0'
        }
        i++
    }
    last := len(str)-1
    if str[last] == '0' {
        str = str[:last]
    }
    
    return str
}



```