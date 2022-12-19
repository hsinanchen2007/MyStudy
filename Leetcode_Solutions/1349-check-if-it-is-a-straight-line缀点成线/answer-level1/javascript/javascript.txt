太简单了吧，没有人做吧，都是100%，激动

var checkStraightLine = function(coordinates) {
    let [x1, y1, x2, y2] = [coordinates[0][0], coordinates[0][1],coordinates[1][0],coordinates[1][1]]
    let k = (y2-y1)/(x2-x1)
    let b = y1 - k * x1
    
    for(let i=2; i<coordinates.length; i++){
        if(k * coordinates[i][0] + b !== coordinates[i][1]) {
            return false
        }
    }
    return true
};