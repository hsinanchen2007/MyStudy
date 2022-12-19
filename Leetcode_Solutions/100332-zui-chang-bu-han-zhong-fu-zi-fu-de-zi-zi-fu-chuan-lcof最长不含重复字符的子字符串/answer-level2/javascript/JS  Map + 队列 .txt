### 代码

```javascript
var lengthOfLongestSubstring = function(s) {
    const map = new Map();
    const queue = [];
    let res = 0;
    for(let i = 0; i < s.length; i++){
        let c = s[i];
        if(map.has(c)){
            res = Math.max(res, queue.length);
            while(queue.length > 0 && map.get(c) !== undefined){
                map.set(queue.shift(), undefined)
            }
        }
        queue.push(c);
        map.set(c, 1);
    }
    res = Math.max(res, queue.length)
    return res
};
```