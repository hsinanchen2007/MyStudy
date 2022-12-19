### 解题思路
暴力循环计算

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var titleToNumber = function(s) {
    var n=[];
    for(var i=0;i<s.length;i++){
       n[i] = s[i].charCodeAt()-64;
    }
    var sum=0;
    for(i=0;i<s.length;i++){           
        for(var j=0;j<s.length-i-1;j++){
            n[i]=n[i]*26;
            }
        sum=sum+n[i];
    }
    return sum;
};
```