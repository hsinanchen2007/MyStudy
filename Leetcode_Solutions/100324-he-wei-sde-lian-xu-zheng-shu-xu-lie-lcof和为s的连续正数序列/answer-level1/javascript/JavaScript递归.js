### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */

var findContinuousSequence = function(target) {
    this.res = [];
    this.t = target;
    for(var i = 1; i <= Math.ceil(t/2); i++){
        backTrack(i, 0, []);
    }
    return res;
};

var backTrack = function(n, sum, item){
    if(sum == this.t){
        this.res.push(item);
        return;
    }else if(sum < this.t){
        item.push(n);
        backTrack(n + 1, sum + n, item);
    }
    
}
```