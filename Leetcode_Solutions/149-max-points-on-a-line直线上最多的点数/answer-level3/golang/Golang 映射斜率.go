```
type Slope struct{
    x, y int
}

func abs(x int) int {
    if x < 0 { 
        return -x ; 
    } else { return x ; }
}
func gcd(x int, y int) int {
    if x > y {
        x, y = y, x ; 
    }
    if x == 0 {
        return y ;
    } else {
        return gcd(y%x, x) ; 
    }
}
func maxPoints(points [][]int) int {
    var ans = 0 ;
    for i:=0; i<len(points); i++ {
        var num int = 0 ; 
        var maxer int = 0 ;
        recorder := make(map[Slope]int)
        for j:=0; j<len(points); j++ {
            if points[j][0] == points[i][0] && points[j][1] == points[i][1] { 
                num ++ ; 
                continue ;
            }
            xDis, yDis := points[j][0] - points[i][0], points[j][1] - points[i][1]
            if(xDis < 0) { xDis, yDis = -xDis, -yDis }
            var DisGCD int = gcd(abs(xDis), abs(yDis))
            xDis, yDis = xDis / DisGCD, yDis / DisGCD
            recorder[Slope{xDis, yDis}] ++ 
            if(recorder[Slope{xDis, yDis}] > maxer) {
                maxer = recorder[Slope{xDis, yDis}]
            }
        }
        if(maxer + num > ans) { ans = maxer + num }
    }
    return ans 
}
```
练习Golang，随便找到Hard试试手，结果是个傻逼题，两分钟A了。