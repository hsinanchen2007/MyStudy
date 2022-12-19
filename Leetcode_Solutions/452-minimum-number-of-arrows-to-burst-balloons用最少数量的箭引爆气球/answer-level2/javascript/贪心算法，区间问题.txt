### 解题思路
想到用贪心算法也想到区间了，但是没有想到取起始点或者终点作为判断依据。

### 代码

```javascript
/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function(points) {
    if(points.length===0) return 0;
    const sort_points = points.sort((p1,p2)=>p1[1]-p2[1]);   //用点的终点作为排序依据
    let arrows = 1;
    let shoot_endX = sort_points[0][1];
    for(let i = 0;i<sort_points.length;i++){
       if(sort_points[i][0]>shoot_endX){                    //若当前点的起点小于shoot_endX，则代表当前一定包含shoot_endX，可一箭射穿。
           arrows++                                         //若大于，则必须要重新射一直箭，并且把该点的终点作为区间判断依据
           shoot_endX = sort_points[i][1]
       }
    }
    return arrows;
};
```