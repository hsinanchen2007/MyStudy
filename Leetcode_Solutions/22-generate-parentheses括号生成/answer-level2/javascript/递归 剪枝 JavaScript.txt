### 解题思路
递归出所有可能，删除不符合条件的字符串
### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    var recusion = function (m){
        if(m <= 0) return[''];
        var res = [];
        var del = recusion(m-1);
        for(var i = 0; i < del.length; i++){
            var s = 0, t = 0;
            var str = del[i].split('');
            for(var j = 0; j < str.length; j++){
                if(str[j] === '(') s++;
                else t++;
            }
            if(s < n){
                res.push(del[i]+'(');
            }
            if(t < s){
                res.push(del[i]+')');
            }
        }
        return res;
    }
    return recusion(2*n);
};
```