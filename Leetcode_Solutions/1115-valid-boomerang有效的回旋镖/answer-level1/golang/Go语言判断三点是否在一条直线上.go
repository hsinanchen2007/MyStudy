![image.png](https://pic.leetcode-cn.com/aea843e1aa98443aaaeb413264bd34804ff56ff239fdfadfdce8c686a05fe64c-image.png)
```
func isBoomerang(points [][]int) bool {
    var res = true
    if points[0][0] == points[1][0] && points[0][0] == points[2][0] || 
            points[0][0] == points[1][0] && points[0][1] == points[1][1] || 
            points[0][0] == points[2][0] && points[0][1] == points[2][1] || 
            points[1][0] == points[2][0] && points[1][1] == points[2][1]{
        res = false
        return res
    }
    if float64(points[0][1]-points[1][1])/float64(points[0][0]-points[1][0]) == float64(points[0][1]-points[2][1])/float64(points[0][0]-points[2][0]){
        res = false
    }
    return res
}
```

