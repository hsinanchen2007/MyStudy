### 解题思路
大概是最烂的解法吧。写了一个Regex然后强行匹配字符串，执行用时似乎还不错，就是内存有点惨

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    var reg = new RegExp('^ *[-+]?[0-9]+');//Regex wins

    var outstr = reg.exec(str);
    if(outstr !== null){
        var res = parseInt(outstr[0]);
        if(Math.sign(res) == 1){
            return Math.min(2147483647, res);
        }
        else if(Math.sign(res) == -1){
            return Math.max(-2147483648,res);
        }
        
    }
    return 0;

};
```