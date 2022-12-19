### 解题思路
思路参照官方题解的数学思路，很精妙。仅提供个人的GO语言实现。

### 代码

```golang
func canMeasureWater(x int, y int, z int) bool {
    if x==0 || y==0{
        return z==0||x+y==z
    }
    if x+y<z{
        return false
    }
    var gcd func(a int,b int) int
    gcd = func(a int,b int) int{
        for a%b!=0{
            a,b=b,a%b
        }
        return b
    }
    return z%gcd(x,y)==0
}
```