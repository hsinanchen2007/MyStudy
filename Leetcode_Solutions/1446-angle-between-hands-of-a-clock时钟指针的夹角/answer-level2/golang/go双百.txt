### 解题思路
此题不配medium

### 代码

```golang
import "fmt"
func angleClock(hour int, minutes int) float64 {
    hAngle := (float64(hour) + float64(minutes) / 60) / 12 * 360
    mAngle := float64(minutes) / 60 * 360
    //fmt.Println(hAngle, mAngle)
    var res float64
    if hAngle >= mAngle {
        pos1 := hAngle - mAngle
        pos2 := 360 - hAngle + mAngle
        if pos1 < pos2 {
            res = pos1
        } else {
            res = pos2
        }
    } else {
        pos1 := mAngle - hAngle
        pos2 := 360 - mAngle + hAngle
        if pos1 < pos2 {
            res = pos1
        } else {
            res = pos2
        }
    }
    return res
}
```