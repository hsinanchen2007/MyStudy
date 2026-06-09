### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {boolean}
 */
var canMeasureWater = function(x, y, z) {
  
   if(x+y<z){
       return false;
   } 
    if(z === 0) {
       return true;
   }
   function gcb(a,b) {
      
      return a%b === 0 ? b : gcb(b,a%b);
   }
   var max = Math.max(x,y); 
   var min = Math.min(x,y);
   if(max === 0 && z!== 0) {
       return false;
   } else if( min === 0 && max !== z ) {

       return false;
   }
   var g = gcb(max,min);
   if(z%g === 0 ){
       return true;
   }
   return false
};
```