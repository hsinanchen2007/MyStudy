```js
var firstUniqChar = function(s) {
    if(s.length === 1) return s;
    
    for(let i of s) {
        if(s.indexOf(i) === s.lastIndexOf(i)){
            return i;   
        }
    }
    return ' ';
};
```