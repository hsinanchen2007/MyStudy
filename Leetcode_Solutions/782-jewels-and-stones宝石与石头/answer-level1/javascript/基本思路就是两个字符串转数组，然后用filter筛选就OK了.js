```
/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function(J, S) {
    let [Jrr,Srr] = [J.split(''),S.split('')]
    return Srr.filter(value=>{ return Jrr.indexOf(value)!==-1 }).length
};
```
