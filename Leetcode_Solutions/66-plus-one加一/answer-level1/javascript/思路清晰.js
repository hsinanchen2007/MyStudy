

转为数字的话会超出范围 直接在数组中搞
```javascript
var plusOne = function(digits) {
     for(let i = digits.length-1;i>=0;i--){ //倒序
         if(digits[i] != 9){  //当最后一位不是9--->让他加一直接返回  （1）
             digits[i]++     
             return digits
         }
         digits[i] = 0; //当最后一位是9 --->该位变成0，进入循环--->  返回（1）
     }
     return [1,...digits]  //很不幸全部都是9 返回一个[1,...很多0]
};
```