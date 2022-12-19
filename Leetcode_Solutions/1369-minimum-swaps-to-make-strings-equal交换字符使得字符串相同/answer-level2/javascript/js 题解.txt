```
/**
 * @param {string} s1
 * @param {string} s2
 * @return {number}
 */
var minimumSwap = function(s1, s2) {
    if(s1.length !== s2.length) {
        return  -1
    }
    let stX = 0
    let stY = 0
    //抽取两数组同位置不同值（x, y）的个数
    for(var i = 0; i < s1.length; i ++) {
        if(s1[i] !== s2[i]) {
            if(s1[i] == 'x') {
                stX ++
            } else {
                stY ++
            }
        } 
    }
   
    //判断差异字符的个数是否为偶数
    if((stX + stY) % 2 === 0) {
        return  stX % 2 === 0 ? (stX + stY) / 2 : (stX + stY) / 2 + 1
    } else {
        return -1;
    }
};
```
