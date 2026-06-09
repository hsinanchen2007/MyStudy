### 解题思路
循环字符串，碰到括号left+1，碰到反括号left-1，若left为0则right+1，最后计算left+right即可

### 代码

```javascript
/**
 * @param {string} S
 * @return {number}
 */
var minAddToMakeValid = function(S) {
    let right=0;
    let left=0;
    for(let i=0;i<S.length;i++) {
        if(S[i] == '(') {
            left++;
        } else {
            if(left == 0) {
                right++;
            } else {
                left--;
            }
        }
    } 
    return left+right; 
};
```