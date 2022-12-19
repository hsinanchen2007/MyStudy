**思路**
三次循环，每轮循环先判断个位数是否与十位数相同，如果相同即为对应的RGB值，否则根据十位数计算出与之比较的上下界，最后把上下界依次与比较值相减看那个差值最小即为对应RGB结果。
需要注意的是如果上界值要考虑是否加一情况，还有如果十位数为0则下界直接为0x00，具体可以看下面代码。

**代码**
```
func similarRGB(color string) string {
    var rgb [3]int
    var s, t int
    var x, y, z int

    for i := 0; i < 3; i++ {
        m, n := color[1+2*i], color[2+2*i]
        if m >= 'a' {
            s = int(m-'a') + 10
        } else {
            s = int(m - '0')
        }
        if n >= 'a' {
            t = int(n-'a') + 10
        } else {
            t = int(n - '0')
        }

        if s == t {
            rgb[i] = s*16 + t
        } else {
            y = s*16 + t
            if s == 0 {
                x = 0
                z = 0x11
            } else {
                x = (s-1)*16 + s - 1
                z = s*16 + s
            }

            if y > z {
                x = z
                z = (s+1)*16 + s + 1
            }
            if y-x >= z-y {
                rgb[i] = int(z)
            } else {
                rgb[i] = int(x)
            }
        }
    }

    return fmt.Sprintf("#%02x%02x%02x", rgb[0], rgb[1], rgb[2])
}
```
