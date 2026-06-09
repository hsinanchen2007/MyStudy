### 解题思路
计算出容器下的所有可能，由于可能值最大值肯定不超过容器参数最大值，时间复杂度及空间复杂度均为O(max(x,y))

### 代码

```golang
func canMeasureWater(x int, y int, z int) bool {
    if( z == 0){
        return true
    }

    

    if( x == 0 || y == 0){
        return false
    }

    max,min := x,y
    if( y > x) {
        max,min = y,x
    }
    if( z > max*2){
        return false
    }
    
    z = z%max

    if( z == 0){
        return true
    }

    if( z == x || z == y){
        return true
    }


    sourceMax := max

    hm := map[int]bool{} //result

    check := func(cp int,provider map[int]bool) bool {
        _,ok := provider[cp]
        if( ok ){
            return false
        }
        provider[cp] = true
        return true
    }

    for i:=0;i<sourceMax;i++ {
        ok := check(max,hm)
        if(!ok) {
            return false
        }
        if( max == z){
            return true
        }

        if ( max > min){
            max = max-min
        } else {
            max = sourceMax - (min-max)
        }

    }

    return false
}
```