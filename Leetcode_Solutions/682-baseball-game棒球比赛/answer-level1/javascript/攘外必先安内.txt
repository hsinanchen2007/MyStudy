### 解题思路

先把内奸C和它同党,清除干净

### 代码

```javascript
/**
 * @param {string[]} ops
 * @return {number}
 */
var calPoints = function(ops) {
    let total = 0

    while(ops.indexOf('C')>-1){
      ops.splice(ops.indexOf('C')-1, 2)
    }

    ops.forEach((item,index) => {
       if(item === '+'){
          if(ops[index-1]&&ops[index-2]){
              ops[index] = +ops[index-1] + +ops[index-2]
              total += ops[index]
          }
      } else if(item === 'D'){
        if(ops[index-1]){
              ops[index] = +ops[index-1] * 2
              total += ops[index]
          }
      } else {
        total += +item
      }
    })
    return total
};
```