```
/**
执行G后位置：dest = dest + d*1 向量运算
无法回到原位置情况：1、执行一次指令后未回到原点且方向不变！
其余情况均为有环，可回到原点！
*/

func isRobotBounded(instructions string) bool {
    dest := []int{0, 0} // 当前位置
    d := []int{0, 1} // 方向向量
    
    for _, v := range instructions {
        if v == 'G' {
            dest[0] += d[0]
            dest[1] += d[1]
          continue
        }
        if v == 'L' {
            if d[0] == 0 {
                d[0], d[1] = -1*d[1], -1*d[0]
            } else {
                d[0], d[1] = d[1], d[0]
            }
            continue
        }
        if v =='R' {
            if d[0] == 0 {
                d[0], d[1] = d[1], d[0]
            } else {
                d[0], d[1] = -1*d[1], -1*d[0]
            }
        }   
    }
    
    if dest[0] == 0 && dest[1] == 0 {
        return true
    }
    if d[0] == 0 && d[1] == 1{
        return false
    }
    return true
}
```