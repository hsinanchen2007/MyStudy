自己先写了个，有点蠢，执行久。参考了题解，修改了下
```
var lengthOfLongestSubstring = function(s) {
    let len = s.length, b = 0, ret = 0, n;
    for(let i = 0; i < len; i++) {
        n = s.slice(b, i).indexOf(s[i]);
        if(n !== -1){
            ret = Math.max(i - b, ret);
            b += n+1;
        }
    }
   return Math.max(ret, len-b);
}
```

