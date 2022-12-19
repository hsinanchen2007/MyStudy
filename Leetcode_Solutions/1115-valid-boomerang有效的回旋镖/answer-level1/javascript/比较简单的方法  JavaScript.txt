1.判断是否在45度角的直线上
2.判断是否有相同的点
3.判断X轴或者Y轴是否在一条直线上

    var isBoomerang = function(points) {
        // 直线
        if(
            points[0][0] == points[0][1] &&
            points[1][0] == points[1][1] &&
            points[2][0] == points[2][1] 
        ){
            return false
        }
        // 相同的点
        if(
            JSON.stringify(points[0]) == JSON.stringify(points[1]) ||
            JSON.stringify(points[0]) == JSON.stringify(points[2]) ||
            JSON.stringify(points[1]) == JSON.stringify(points[2])
        ){
            return false
        }
        // X轴或者Y轴是否在一条执行上
        if(points[0][0] == points[1][0] || points[0][0] == points[2][0]){
            return points[1][0] != points[2][0]
        }
        if(points[0][1] == points[1][1] || points[0][1] == points[2][1]){
            return points[1][1] != points[2][1]
        }
        return true
    };