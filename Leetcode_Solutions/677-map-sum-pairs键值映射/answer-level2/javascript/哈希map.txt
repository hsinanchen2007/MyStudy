```js
var MapSum = function() {
    this.map = new Map();
};
MapSum.prototype.insert = function(key, val) {
    this.map.set(key, val);
};
MapSum.prototype.sum = function(prefix) {
    var caculator = 0;
    this.map.forEach((val, key)=>key.indexOf(prefix)==0?caculator+=val:'');
    return caculator;
};
```