
击败了 99.92% 的中文用户,faster than 67.81% of JavaScript online submissions。。。

```javascript []
var isPalindrome = function(x) {
    var result =true;
    var str=x+"";
    for(let i=0;i<str.length/2;i++){
        if(str.charAt(i)!=str.charAt(str.length-i-1)){
            result = false;
            break;
        }
    }
    return result
};
```
