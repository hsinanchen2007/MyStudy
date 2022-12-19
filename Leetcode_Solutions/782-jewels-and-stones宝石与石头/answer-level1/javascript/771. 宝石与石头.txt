### 解题思路
先建立宝石map再查询

### 代码

```javascript
/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function(J, S) {
    let count = 0, checkMap = {}
    for(let i = 0; i < J.length; i++){
        checkMap[J[i]] = true
    }
    for(let i = 0; i < S.length; i++){
        if(checkMap[S[i]]){
            count++
        }
    }
    return count
};
```