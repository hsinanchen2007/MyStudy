```
var UndergroundSystem = function() {
    this.checkInArr = [];
    this.checkOutArr = [];
};

UndergroundSystem.prototype.checkIn = function(id, stationName, t) {
    this.checkInArr.push({ id, stationName, t });
};

UndergroundSystem.prototype.checkOut = function(id, stationName, t) {
    this.checkOutArr.push({ id, stationName, t });
};

UndergroundSystem.prototype.getAverageTime = function(startStation, endStation) {
    let count = 0;
    let time = 0;
    for (let obj of this.checkInArr) {
        if (obj.stationName == startStation) {
            for (let out of this.checkOutArr) {
                if (out.id == obj.id && out.stationName == endStation) {
                    ++count;
                    time += out.t - obj.t;
                }
            }
        }
    }
    return time / count;
};
```
