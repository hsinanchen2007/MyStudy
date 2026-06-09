```js
// 验证是否是回文串
var isPalindrome = function(s, i = 0, j = s.length - 1) {
    while (i < j) {
        if(s[i] !== s[j]){
           return false;
        }
        i++;
        j--;
    }
    return true; 
};

var validPalindrome = function(s) {
    let i = 0;
    let j = s.length - 1;
    while(i < j) { 
        if (s[i] !== s[j]) {
            return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1)
        }
        i++;
        j--;
    }
    return true;
};
```

