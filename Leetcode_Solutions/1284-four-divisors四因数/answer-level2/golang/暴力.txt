### 解题思路
注意四次方特性哈。  

### 代码

```golang
func sumFourDivisors(nums []int) int {
    res := 0
    for _, num := range nums {
        res += getDivisors(num)
    }
    return res
}

func getDivisors(num int) int {
    res := make([]int, 0)
    cnt := 0
    sq := int(math.Sqrt(float64(num)))
    for i := 2; i <= sq; i++{
        if num%i == 0 {
            cnt++
            res = append(res, i)
        }
        if cnt > 1 {
            break
        }

    }
    ret := 0
    if len(res) == 1 && sq * sq != num {
        ret = 1 + num/res[0] + res[0] + num
    }
    return ret
}
```