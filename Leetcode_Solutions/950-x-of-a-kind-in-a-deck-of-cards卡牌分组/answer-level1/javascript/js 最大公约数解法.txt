```
/* 
每组有大于2的相同数字，
其实就是每个不同元素个数的公约数大于2即可
*/
var hasGroupsSizeX = function(deck) {
 // 1 遍历数组获取每个元素的个数
 let countMap = {}
 let gcd = (x,y)=>{return x===0?y:gcd(y%x,x)}
 deck.forEach(s => {
   countMap[s]?countMap[s]++:countMap[s] = 1
 });
 // 求出每个元素个数的公约数
 
 let keys = Object.keys(countMap)
 let g = countMap[keys[0]]
 for(let k = 1 ; k < keys.length ; k++){
    g = gcd(g,countMap[keys[k]])
 }
 return g>1
};
```
