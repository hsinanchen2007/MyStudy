### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} guess
 * @param {number[]} answer
 * @return {number}
 */
var game = function(guess, answer) {
    return guess.filter((val,index)=>{
        return val === answer[index]
    }).length
};
```