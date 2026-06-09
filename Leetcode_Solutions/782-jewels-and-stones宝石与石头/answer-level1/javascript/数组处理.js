### 解题思路
先把字符串转换为数组，再进行处理

### 代码

```javascript
/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
//优化版
var numJewelsInStones = function(J, S){
    var Jarr = J.split("");
    var Sarr = S.split("");
    return Sarr.filter(i=>{ return Jarr.includes(i)}).length;
}
/*var numJewelsInStones = function(J, S) {
    var count = 0;
    for(i=0;i<S.length;i++){
        for(j=0;j<J.length;j++){
            if(J[j]===S[i]){
                count++
            }
        }
    }
    return count;
};*/



```