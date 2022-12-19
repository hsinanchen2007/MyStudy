var findMinArrowShots = function(points) {
    if(points.length == 0){return 0}
    points.sort((a,b)=>{return a[1]-b[1]})
    var count = 1
    var end = points[0][1]
    for(var i = 1;i<points.length;i++){
        if(points[i][0]<=end){
            continue
        }
        end = points[i][1]
        count++
    }
    return count
};