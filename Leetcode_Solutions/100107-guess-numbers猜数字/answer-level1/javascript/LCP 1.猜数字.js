### 解题思路
根据题意可以看出只需要比较guess数组和answer数据对应的数值是否一样即可

### 代码

```javascript
/**
 * @param {number[]} guess
 * @param {number[]} answer
 * @return {number}
 */
var game = function(guess, answer) {
   let nums=0;
   for(let i=0;i<guess.length;i++){
       if(guess[i]===answer[i]){//如果一样nums加一
           nums++
       }
   }  
   return nums
};
```