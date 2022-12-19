### 解题思路
栈存储的是下标，然后判断的是值，如果找到比栈顶大的，就减下标
注意：有可能后边的数会比前边N个数大，所以用while

### 代码

```javascript
/**
 * @param {number[]} T
 * @return {number[]}
 */
var dailyTemperatures = function(T) {
    let result = new Array(T.length).fill(0)
    if(T.length <=0){return result}
    let stack = [0]
   for(let i =1; i< T.length; i++){

       while(T[stack[stack.length -1]] < T[i] && stack.length !=0){
           result[stack[stack.length -1]] = i - [stack[stack.length -1]]
           let temp = stack.pop()
       }
       stack.push(i)
       
   }

   return result
};
```