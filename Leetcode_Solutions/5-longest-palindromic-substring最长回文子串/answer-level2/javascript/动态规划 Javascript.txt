### 解题思路
动态规划，temp[j][i]表示j到i位的子串为回文，temp[j][i]为回文的条件即为temp[j]==temp[i]且temp[j+1][i-1]也为回文。

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    var res= "";
    var temp = new Array(s.length);
    for (var k=0;k<temp.length;k++){
        temp[k]= new Array(s.length);
    }
    for(var i=0;i<s.length;i++){
        for(var j=0;j<=i;j++){
            if(s[i]==s[j] && (i-j<2||temp[j+1][i-1]==true)){
                temp[j][i] = true;
            }
            if(temp[j][i]==true && (i-j+1>res.length)){
                res = s.substring(j,i+1);
            }
        }
    }
    return res;
};
```