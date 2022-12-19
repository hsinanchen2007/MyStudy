### 解题思路
注意判断不为null,不能判断为真，因为有0的时候

### 代码

```javascript
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
     let dict = {}
     for(let i = 0; i< numbers.length; i++){
         if(dict[target - numbers[i]] !=null){
             return [dict[target - numbers[i]] +1 , i +1]
         }

         dict[numbers[i]] = i
     }

   return [0,0]
};
```