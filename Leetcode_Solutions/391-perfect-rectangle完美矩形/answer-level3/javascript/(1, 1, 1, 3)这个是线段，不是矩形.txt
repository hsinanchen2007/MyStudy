```
/**
 * @param {number[][]} rectangles
 * @return {boolean}
 */
var isRectangleCover = function(rectangles) {
    let l0 = Infinity
    let l1 = Infinity
    let l2 = -Infinity
    let l3 = -Infinity
    for(let x of rectangles) {
        if(x[0] < l0) l0 = x[0]
        if(x[1] < l1) l1 = x[1]
        if(x[2] > l2) l2 = x[2]
        if(x[3] > l3) l3 = x[3]
    }
    const h = new Array(l2 - l0).fill(l1)
    rectangles.sort((a, b) => a[1] - b[1])
    for(let x of rectangles) {
        for(let i = x[0]; i < x[2]; i++) {
            if(h[i - l0] !== x[1]) return false
            h[i - l0] = x[3]
        }
    }
    for(let i = 0; i < h.length; i++) {
        if(h[i] !== l3) return false
    }
    return true
};
```
