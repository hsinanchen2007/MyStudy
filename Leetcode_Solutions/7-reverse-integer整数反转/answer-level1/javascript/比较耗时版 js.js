```
var reverse = function(x) {

  let g = x>0 ?1:-1
    let y = (x*g+'').split('').reverse().join('')*g
    if(y+1>Math.pow(2,31)||y<=-Math.pow(2,31)) return 0
    return y
};
```
