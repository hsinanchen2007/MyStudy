/**
 * Initialize your data structure here.
 * @param {number} size
 */
var MovingAverage = function(size) {
    let a = new Array(size).join(',').split(',').map(_=> '')
    MovingAverage.prototype.arr = a;
};

/** 
 * @param {number} val
 * @return {number}
 */
MovingAverage.prototype.next = function(val) {
    const arr  = MovingAverage.prototype.arr
    const length  = MovingAverage.prototype.arr.length
    let result = 0;
    let times = 0
    const reducer = (accumulator, currentValue) => {
        return accumulator + currentValue
      };
    if(arr.reduce(reducer) === 0) {
        arr.push(val)
        arr.shift()
        return val;
    } else {
       arr.push(val)
        if(arr.length > length){
            arr.shift()
        }
        arr.map(item =>{
            if(item !== '' ) {
                times ++;
                result += item;
            }
        })
        // MovingAverage.prototype.arr = arr
        return result/times
    }
};