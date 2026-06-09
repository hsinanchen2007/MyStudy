### 解题思路
- 通过obj 和 for（let of）函数进行遍历，统计数组中数字的个数，通过 Object.value 得到统计数;
- 然后通过 Array.every() 判断每一个统计数是否满足是 X 的条件；
- gcd 函数判断 是否满足 X 的条件;

### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function(deck) {
    function gcd(x, y) {
        return x == 0 ? y : gcd(y%x, x);
    }
    debugger;

    let obj = {};
    for(let i of deck) {
        obj[i] = !obj[i] ? 1 : ++obj[i];
    }

    let arr = Object.values(obj);
    let res = arr[0];
    return arr.every(i => (res = gcd(res, i)) > 1);
}


```