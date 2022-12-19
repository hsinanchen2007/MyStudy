### 解题思路
map遍历或者for遍历

### 代码

```javascript
/**
 * @param {number[]} numbers
 * @return {number}
 */
var minArray = function(numbers) {
    let minNum=numbers[0];
    // for(let i of numbers){
    //     minNum= minNum < i ?  minNum:i
    //     console.log(minNum)
    // }
    numbers.map(i=>{
        minNum= minNum < i ?  minNum:i
    })
    return minNum
};
```