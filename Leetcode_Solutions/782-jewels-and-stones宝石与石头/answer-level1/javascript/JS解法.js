### 解题思路
借鉴修改的两个方法。
一种是变数组用filter、includes方法进行循环对照，得到一个所有宝石的数组，其长度为结果；
另一种是用for循环、indexOf查找索引、if条件判断是否为宝石，符合条件的次数为结果；
这两个是个人感觉最简洁的两种方法。
### 代码

```javascript
/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function(J, S) {
    return S.split('').filter(v=>J.includes(v)).length
};


var numJewelsInStones = function(J, S) {
    let a=0;
    for(var i=0;i<S.length;i++){
        if(J.indexOf(S[i])!=-1){
            a++
        }
    }
    return a;
}
```