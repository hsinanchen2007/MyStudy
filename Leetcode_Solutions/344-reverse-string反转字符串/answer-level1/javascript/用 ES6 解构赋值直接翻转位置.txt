ES 6 结构赋值可以直接交换位置，i 位置对应length-1-i位置，数组长度是奇数时，中间位置不用交换位置
```javascript
var reverseString = function(s) {
   for(let i = 0;i < s.length/2;i++){
       [s[i],s[s.length-1-i]] = [s[s.length-1-i],s[i]]
   }   
};

```
