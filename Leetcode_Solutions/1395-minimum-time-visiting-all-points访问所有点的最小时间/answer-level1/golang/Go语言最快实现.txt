思路：计算两点间的最短路径为计算两点横纵坐标绝对值的最小者

func minTimeToVisitAllPoints(points [][]int) int {
	var sum int = 0
	for i := 0; i<len(points)-1; i++ {
		x := int(math.Abs(float64(points[i+1][0] - points[i][0])))
		y := int(math.Abs(float64(points[i+1][1] - points[i][1])))
		temp := x
		if y > x {
			temp = y
		}
		sum += temp
	}
    return sum
}


总结：Go语言中取绝对值的方法为math.Abs其中参数为float 64类型，传入时需要转换为float 64类型，解读时需要转换回int类型。