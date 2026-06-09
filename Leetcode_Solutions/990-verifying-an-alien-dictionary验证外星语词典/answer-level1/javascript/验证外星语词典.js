```js
var isAlienSorted = function(words, order) {
    let map = new Array(26);
    for(let i = 0; i < order.length; i++){
        map[order[i].charCodeAt()-97] = i;
    }
    for(let i = 1; i < words.length; i++){
        if(map[words[i][0].charCodeAt()-97] <= map[words[i-1][0].charCodeAt()-97]) return false;
    }
    return true;
};
```

参考官方题解