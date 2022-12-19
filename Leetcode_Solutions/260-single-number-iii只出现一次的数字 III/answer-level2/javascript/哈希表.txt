```js
var singleNumber = function(nums) {
    var res = [];
    var map = new Map();
    nums.forEach(v=>map.has(v)?map.set(v, map.get(v)+1):map.set(v, 1));
    map.forEach((v, k)=>v===1?res.push(k):'');
    return res;
};
```