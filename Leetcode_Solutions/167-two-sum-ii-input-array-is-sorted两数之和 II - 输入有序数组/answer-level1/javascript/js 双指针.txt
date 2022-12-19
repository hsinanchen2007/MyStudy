### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
// var twoSum = function(numbers, target) {
//     for(var i=0, len=numbers.length; i<len; i++){
//         var temp = target-numbers[i];
//         if(temp < numbers[i]){
//             continue;
//         }else{
//             if(numbers.slice(i+1, len).indexOf(temp) !== -1){
//                 return [i+1, numbers.slice(i+1, len).indexOf(temp) + i+2 ]
//             }else{
//                 continue;
//             }
//         }

//     }
//     return [0, 0];
// };

var twoSum = function(numbers, target) {
   var i=0, j=numbers.length-1;
   while(i<j){
       var temp = target-numbers[i];
       if(numbers[j] > temp){
           j--;
       }else if(numbers[j] < temp){
           i++;
       }else{
           return [i+1, j+1];
       }
   }
   return []
};



```