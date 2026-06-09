var minTimeToVisitAllPoints = function(points) {
    var len = points.length;
    var minTime = 0;
    for(var i = 0; i < len - 1; i ++) {
        var disX = Math.abs(points[i][0] - points[i + 1][0]);  
        var disY = Math.abs(points[i][1] - points[i + 1][1]);  
        minTime += disX > disY ? disX : disY;
    }
    return minTime;
}