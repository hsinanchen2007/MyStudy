哈希表
```
var longestPalindrome = function(s) {
    const len = s.length;
    if(len < 2) return len;
    const resord = {};
    return s.split('').reduce((t, i) => {
        resord[i] = !resord[i] ? 1 : resord[i] + 1;
        if(!(resord[i] % 2)) t += 2;
        return t;
    }, 0) + (Object.values(resord).some(t => t % 2) ? 1 : 0);
};
```
