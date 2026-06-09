### 解题思路


### 代码

```javascript
/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    var s=['','1','11','21','1211','111221'];
     if(n<=5){
        return s[n];
    }
    for(var i=6;i<=n;i++){
        s[i]='';
        var count=1;
        var res;
        for(var j=0;j<s[i-1].length;j++){
            if(s[i-1][j]==s[i-1][j+1]){
                count++;
            }else{
                res=s[i-1][j];
                s[i]=s[i]+count+res;
                count=1;
            }
        }
    }
    return s[n];
};
```