### 代码

```javascript
var lengthOfLongestSubstring = function(s) {
    const map = new Map();
    const queue = [];
    let res = 0;
    for(let i = 0; i < s.length; i++){
        if(map.has(s[i])){
            res = Math.max(res, queue.length)
            while(queue.length > 0 && map.get(s[i]) != undefined){
                map.set(queue.shift(), undefined)
            }
        }
        queue.push(s[i]);
        map.set(s[i], 1);
    }
    res = Math.max(res, queue.length)
    return res
};
```