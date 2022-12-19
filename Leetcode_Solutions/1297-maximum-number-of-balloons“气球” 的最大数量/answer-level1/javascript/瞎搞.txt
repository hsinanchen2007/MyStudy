### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} text
 * @return {number}
 */
var maxNumberOfBalloons = function(text) {
   let list = text.split('').filter(t => 'balon'.indexOf(t) > -1)
   let obj = {}
   list.forEach(item => {
     obj[item] = obj[item] ? obj[item] + 1 : 1
   })
   let a = Math.min(obj['a']||0, obj['b']||0, obj['n']||0)
   let b = Math.min(obj['o']||0, obj['l']||0)
   if( 2 * a >= b){
    return Math.floor(b / 2)
   }
   return a
};
```