### 解题思路
取两数组最小长度，循环匹配相同值个数；

### 代码

```javascript
/**
 * @param {number[]} guess
 * @param {number[]} answer
 * @return {number}
 */
var game = function(guess, answer) {
    var count= Math.min(guess.length,answer.length);
    var out=0
    for(var i=0;i<count;i++){
        if(guess[i] === answer[i])
            out++;
    }
    return out
};
```