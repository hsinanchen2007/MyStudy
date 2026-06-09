### 解题思路
一步步判断，待更新

### 代码

```javascript
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    var thousand = parseInt(num/1000);
    var hundred = parseInt(num%1000/100);
    var ten = parseInt(num%100/10);
    var one = num%10;

    var m = thousand;
    var cm = parseInt(hundred/9);
    var d = parseInt(hundred/5);
    var cd = parseInt(hundred/4);
    var c = hundred;
    var xc = parseInt(ten/9);
    var l = parseInt(ten/5)
    var xl = parseInt(ten/4);
    var x = ten;
    var ix = parseInt(one/9);
    var v = parseInt(one/5);
    var iv = parseInt(one/4);
    var i = one;

    var arr = [];
    var push = (s,str) => {
        for(var i = 0; i < s; i++)
            arr.push(str)
    }
    push(m, 'M');
    push(cm || d || cd || c, cm ? 'CM' : d ? 'D' : cd ? 'CD' : 'C');
    push(cm ? 0 : d ? c-5 : 0, 'C');
    push(xc || l || xl || x, xc ? 'XC' : l ? 'L' : xl ? 'XL' : 'X');
    push(xc ? 0 : l ? x-5 : 0, 'X');
    push(ix || v || iv || i, ix ? 'IX' : v ? 'V' : iv ? 'IV' : 'I');
    push(ix ? 0 : v ? i - 5 : 0, 'I');
    return arr.join('');
};
```