### 解题思路
1. 利用对象 o 遍历存储 各牌 出现的次数，并用 Object.values(o) 转化为各牌数对应数组。
2. 存储 并使用Array.every() 判断数组各牌数是否整除 x 。
![image.png](https://pic.leetcode-cn.com/58ed9e0827b97a8e30c028ae0a8cc1ab93c51dc3dbeafea70a4708f29427b6e8-image.png)

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
/**
 * 解法一：
 *      1. 利用对象 o 遍历存储 各牌 出现的次数，并用 Object.values(o) 转化为各牌数对应数组。
 *      2. 存储 并使用Array.every() 判断数组各牌数是否整除 x 。
 */
var hasGroupsSizeX = function(deck) {
    let o = {}, max = 0;
    for(let i=0; i<deck.length; i++){
        const t = deck[i]
        if( !o[t] ) o[t] = 1
        else o[t]++
        max = Math.max(max,o[t])
    }
    const arr = Object.values(o)
    let x=2;
    while( x <= max ){ 
        if( arr.every( item=> item % x == 0 ) ) return true
        x++
    }
    return false
};
```