```
/**
 * @param {number[][]} points
 * @return {boolean}
 */
var isConvex = function(points) {
    function check(p1,p2,points){
        var above = [];
        var below = [];
        for(var i = 0;i<points.length;i++){
            var point = points[i];
            // point[1] = 
            var y = (point[0]-p1[0]) * (p2[1]-p1[1])/(p2[0]-p1[0]) + p1[1];
            if(point[1]>y){
                above.push(point);
            }
            if(point[1]<y){
                below.push(point);
            }
        }
        if(above.length && below.length){
            return false;
        }
        return true;
    }
    for(var i = 0;i<points.length-1;i++){
        //获取一条边线两个点
        var p1 = points[i];
        var p2 = points[i+1];
        //推到公式
        //把所有点代入公式判断是否分割
        if(!check(p1,p2,points)){
            return false;
        }
    }
    
    return true;
};
```
