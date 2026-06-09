### 解题思路


### 代码

```golang
func myAtoi(str string) int {
    if len(str) == 0{
        return 0
    }
    var space , positive, negetive rune
    space = ' '
    positive = '+'
    negetive = '-'

    flag := 0
    res := make([]int,0)
    nums := make([]int,10)

    for k,_ := range nums {
        nums[k] = k
    }


    for _,v := range str {
        if len(res)==0 && flag != 0 && (v <'0'|| v>'9' || v == space){
            return 0       
        }
        if len(res)==0 && v == space {
            continue
        } else if v != space && len(res) == 0 {
            if v == negetive || v == positive || (v <='9' && v >= '0'){
                if v <='9' && v>='0' {
                    t := nums[v-'0']
                    res = append(res,t)
                } else {
                    if flag != 0 {
                        return 0
                    }
                    if v == negetive && flag == 0{
                        flag = -1
                    } else if v == positive && flag == 0{
                        flag = 1
                    }
                }
                continue
            } else {
                return 0
            }
        }
        if len(res)>0 && (v>='0' && v <= '9') {
            t := nums[v-'0']
            res = append(res,t)
        } else if len(res)>0 && (v<'0' || v >'9') {
            break
        }
    }
    if len(res) == 0{
        return 0
    }

    if flag == 0 {
        flag = 1
    }

    ans := 0
    ten := 1

    for i:=len(res)-1;i>=0;i-- {
        if  res[0]>0 && (ans > 2147483647 || ten > 2147483647){
            if flag > 0 {
                return 2147483647
            } else {
                return -2147483648
            }
        }
        ans += res[i]*ten
        ten *= 10
        
    }
    if ans > 2147483647 {
            if flag > 0 {
                return 2147483647
            } else {
                return -2147483648
            }
    }

    return ans*flag
}
```