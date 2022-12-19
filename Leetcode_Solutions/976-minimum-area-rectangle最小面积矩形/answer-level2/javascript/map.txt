思路:将每一个存入map中，便于后期能够快速查找是否存在某一个点。
     area变量存放最小面积值，初始值为Infinity
     双循环，将点两两组合，作为矩形的对角线，通过map确定另外一条对角线的两点是否存在，如果存在，计算矩形面积，判断如果小于area，则更新area。
```
/**
 * @param {number[][]} points
 * @return {number}
 */
var minAreaRect = function(points) {
    let map = new Map();
    
    /*将每个点存入map*/
    points.forEach(ele=>{
        map.set(ele[0]+","+ele[1],true);
    });
    
    let len = points.length,
        area = Infinity;
    
    /*枚举每个点作为对角线*/
    for(let i = 0;i < len-1;i++){
        for(let j = i+1;j < len;j++){
            let leftup = points[i];
            let rightdown = points[j];
            /*判断两点是否在同一条线上*/
            if(leftup[0]!==rightdown[0] && leftup[1]!==rightdown[1]){
                /*判断点中是否存在另一条对角线的两点*/
                if(map.get(leftup[0]+","+rightdown[1]) && map.get(rightdown[0]+","+leftup[1])){
                    let cur = Math.abs(leftup[0]-rightdown[0]) * Math.abs(leftup[1]-rightdown[1]);
                    area = cur < area ? cur : area;
                }
            }
        }
    }
    if(area!=Infinity){
        return area;
    }else{
        return 0;
    }
};
```
