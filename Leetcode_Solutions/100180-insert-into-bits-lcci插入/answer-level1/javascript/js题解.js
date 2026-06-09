```
// 有两点需要注意，1，MN是整数，不是二进制。2，ij不一定正好是M的位数，所以需要补0
var insertBits = function(N, M, i, j) {
    let Nr = N.toString(2).split('').reverse();
    let Mr = M.toString(2).split('').reverse();
    for(let k = i; k <= j; k++){
        Nr[k] = Mr[k - i] ? Mr[k - i]: '0'; // 补0
    }
    return ('0b' + Nr.reverse().join('')) / 1;
};
```
前端算法库：https://github.com/cunzaizhuyi/js-leetcode  
这里记录了我刷过的近500道LeetCode的题解，