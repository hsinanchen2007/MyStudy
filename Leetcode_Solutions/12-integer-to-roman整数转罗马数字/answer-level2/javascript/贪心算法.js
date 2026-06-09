### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    var codes = ["I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"];
    var list =  [1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000];
    var arr = [];
    var total = 0;
    var str = '';

    for (var i = list.length - 1; i >= 0; i--) {
        var val = list[i];
        while((total + val) <= num) {
            total += val;
            arr.push(i);
        }
    }

    arr.map(index => {
        str += codes[index];
    })

    return str;
};
```