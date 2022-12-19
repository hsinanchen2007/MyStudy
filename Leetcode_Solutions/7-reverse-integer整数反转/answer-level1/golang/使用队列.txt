### 解题思路
第一时间想到是利用队列的思想来解题，通过将所有的低位入队列，对头依次取还原即可。

### 代码

```golang
func reverse(x int) int {
    l := list.New()
    for{
        if x != 0 {
            highBit := x % 10 
            l.PushBack(highBit)
        }else{
            break
        }
        x = x / 10
    }
    var retValue int
    for e := l.Front(); e != nil; e = e.Next() {
        value := e.Value.(int)
        retValue = retValue * 10 + value
    }

    if x < 0 {
        retValue = - retValue
    }

    rangeInt := 1 << 31
    if retValue < -rangeInt || retValue > (rangeInt - 1) {
        return 0
    }

    return retValue
}
```