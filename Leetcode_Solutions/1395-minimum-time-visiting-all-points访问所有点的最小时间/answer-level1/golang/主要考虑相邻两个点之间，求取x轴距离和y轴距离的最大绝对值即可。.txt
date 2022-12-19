```
func minTimeToVisitAllPoints(points [][]int) int {
    maxStep := 0
    firstPoint := points[0]
    for i := 1; i< len(points); i++ {
        xVal := points[i][0]
        yVal := points[i][1]

        diffX := xVal - firstPoint[0]
        diffY := yVal - firstPoint[1]

        if diffX < 0 {
            diffX = diffX * -1
        }

        if diffY < 0 {
            diffY = diffY * -1
        }
   
        if diffX >= diffY {
            maxStep = maxStep + diffX
        } else {
            maxStep = maxStep + diffY
        }

        firstPoint = points[i]
    }

    return maxStep
}
```
