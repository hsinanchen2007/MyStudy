*法一：循环，比较首尾字符*

```js
var isPalindrome = function(s) {
    if (s == null || s.length == 0) {
        return true;
    }
    s = s.replace(/[^0-9a-zA-Z]/g, '').toLowerCase();
    var len = s.length;
    var middle = Math.floor((len-1)/2);
    for(var i = 0; i <= middle; i++) {
        if(s[i] !== s[len-1-i]) {
            return false
        }
    }
    return true;
};
```

*法二：双指针*

思想同法一，比法一慢点

```js
var isPalindrome3 = function(s) {
    s = s.replace(/[^a-zA-Z0-9]/g,"").toLowerCase();
    let i = 0,j = s.length - 1;
    while (i < j) {
        if(s[i] !== s[j]){
           return false;
        }
        i++;
        j--;
    }
    return true;
};
```

*法三：借助数组reverse()方法*

速度较快，不过耗内存

```js
var isPalindrome2 = function(s) {
    if (s == null || s.length == 0) {
        return true;
    }
    s = s.replace(/[^0-9a-zA-Z]/g, '').toLowerCase();
    var s2 = s.split('').reverse().join('');
    return s === s2;
};
```


