``` js
/**
 * @param {string} source
 * @param {string} target
 * @return {number}
 */
var shortestWay = function(source, target) {
    var t = 0,
        s = 0,
        count = 0;

    while(t < target.length) {
        if(source.indexOf(target[t]) === -1) {
            return -1
        }

        if(target[t] === source[s]) {
            t++;
            s++;
        } else {
            s++;    
        }

        if(s >= source.length) {
            count++;
            s = 0 ;
        }
    }

    if(t >= target.length && s !== 0) {
        count++;
    }

    return count;
};
```
