```
var calculateTime = function(keyboard, word) {
    let map = new Map();
    keyboard.split('').map( (v,i)=>{
        map.set(v,i)
    } )
    let result = previous = 0;
    word.split('').map( (v,i)=>{
        result += Math.abs( map.get(v) - previous )
        previous = map.get(v)
    } )
    return result
};
```
