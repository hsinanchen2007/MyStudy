JS解这题属实快
```js
var strToInt = function(str) {
  str = str.trim();
  let res = parseInt(str);
  if(isNaN(res)) return 0;
  let minValue = Math.pow(-2, 31);
  let maxValue = Math.pow(2, 31) -1
  if(res < minValue) return minValue
  if(res > maxValue) return maxValue; 
  return res
};
```