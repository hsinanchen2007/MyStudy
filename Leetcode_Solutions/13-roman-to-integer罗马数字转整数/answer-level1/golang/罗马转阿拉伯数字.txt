### 解题思路
条件判断一定要仔细

### 代码

```golang
func romanToInt(s string) int {
    var res int
    for i := 0; i <len(s); i++{
        switch s[i]{
            case 'M':
            if i > 0 && s[i-1] == 'C'{
                res += 900
            }else{
                res += 1000
            }
            case 'D':
              if i > 0 && s[i-1] == 'C'{
                res += 400
            }else{
                res += 500
            }
            case 'C':
            if i < len(s)-1 && (s[i+1] == 'D' || s[i+1] == 'M'){
                continue
            }else{
                if i >0 && s[i-1] == 'X'{
                    res += 90
                 } else{
                   res += 100
                 }
            }
     
            case 'L':
            if i >0 && s[i-1] == 'X'{
                    res += 40
              } else{
                   res += 50
                }
            case 'X':
            if i <len(s)-1 && (s[i+1] == 'L' || s[i+1] == 'C'){
                continue
            }else{
                if i >0 && s[i-1] == 'I'{
                        res += 9
                    } else{
                        res += 10
                    }
            }
               
            case 'V':
              if i >0 && s[i-1] == 'I'{
                    res += 4
                } else{
                  res += 5
                }
            case 'I':
            if i <len(s)-1 && (s[i+1] == 'V' || s[i+1] == 'X'){
                continue
            }else{
                res += 1
            }

        }
    }
    return res
}
```