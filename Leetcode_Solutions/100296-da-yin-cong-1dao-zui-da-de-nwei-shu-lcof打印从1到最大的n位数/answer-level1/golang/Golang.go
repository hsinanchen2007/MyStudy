### 代码

```golang
import "math"

func printNumbers(n int) []int {
    end:=int(math.Pow10(n))-1
    res:=make([]int,end)
    for i:=0;i<end;i++{
        res[i]=i+1
    }
    return res
}
```