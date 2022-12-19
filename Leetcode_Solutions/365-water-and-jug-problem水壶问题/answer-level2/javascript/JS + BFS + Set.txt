```
/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {boolean}
 */
var canMeasureWater = function(x, y, z) {
    let stack = [[0,0]];
    let self = new Set();
    
    while(stack.length > 0){
        let temp = stack.pop();
        let rx = temp[0],ry = temp[1];
        if(rx == z || ry == z || ry + rx == z){
            return true;
        }
        let now = rx + 'a' + ry;
        if(self.has(now)){
            continue;
        }
        
        self.add(rx + 'a' + ry);
        stack.push([x,ry]);
        stack.push([rx,y]);
        stack.push([0,ry]);
        stack.push([rx,0]);
        stack.push([rx-Math.min(rx,y-ry),ry+Math.min(rx,y-ry)]);
        stack.push([rx+Math.min(ry,x-rx),ry-Math.min(ry,x-rx)]);
    }

    return false;
};
```
