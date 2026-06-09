// 假如👻特别聪明，那它直接赶到终点并守在那里等着👨来就好了，只要👻比👱先（或同时）到终点，那么👻一定能抓住👱

// ```javascript
var escapeGhosts = function(ghosts, target) {
    let stepMine = Math.abs(target[0])+Math.abs(target[1]);
    let minStep = Infinity;
    for(let [x,y] of ghosts){
        let step = Math.abs(x-target[0]) + Math.abs(y-target[1]);
        minStep = Math.min(step,minStep);
        if(minStep<=stepMine)return false;
    }
    return true;
};
// ```