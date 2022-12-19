```
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    const basicSign = { //列出所有大体的情况
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000
    };
    
    let result = 0;
    let _arr = s.split('');

    // 假设没有特殊情况下 一一加加
    result = _arr.reduce((total, num) => {
        return total + basicSign[num];
    }, 0);
    
    // 第二步考虑特殊情况 将之前特殊情况找出来
    const keys = ['CM', 'XC', 'IV', 'IX', 'XL', 'CD'];
    keys.forEach((item, index) => {
        if(s.indexOf(item) > -1) {
          result -= 2 * basicSign[item.split('')[0]]
        }
    });
    
    return result;
};
```