```
import (
	"fmt"
	"strconv"
)
func convertToBase7(num int) string {

    if num == 0 {
        return "0"
    }
    nagetive := false
    if num < 0 {
        num *= -1
        nagetive = true
    }
    var ret string
    for{
        if num <= 0 {
            break
        }
        ret += strconv.Itoa(num % 7)
        num /= 7
    }
    if nagetive{
        ret += "-"
    }
    return reverce(ret)
}

func reverce(str string) string {
    var ret string
    strlen := len(str)
    for i := 0; i < strlen; i++ {
        ret += string(str[strlen - 1 - i])
    }
    return ret
}
```
