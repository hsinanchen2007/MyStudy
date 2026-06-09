```
var checkStraightLine = function(coordinates) {
    let count = 0
    let k = (coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0])
    coordinates.forEach((item)=>{
        let k2 = (item[1]-coordinates[0][1])/(item[0]-coordinates[0][0])
            if (k2 === k || isNaN(k2)){
                count++
            }
    });
    return  (count === coordinates.length)
};
```