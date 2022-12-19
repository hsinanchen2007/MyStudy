法一： 一遍循环一遍删除存在的字符串，最后留下不同的。
```js
var findTheDifference = function(s, t) {
    for (let i = 0; i < s.length; i++) {
        let index = t.indexOf(s[i])
        if (index !== -1) {
            //t = t.substring(0, index) + t.substring(index + 1, t.length)
            t = t.replace(s[i], '')
        }
    }
    return t
};
```

法二：借助map对象
```js
var findTheDifference2 = function(s, t) {
    let map = new Map();
    for ( let i = 0; i < s.length; i++) {
        let val = map.get(s[i]);
        map.set(s[i], val === undefined ? 1 : val + 1);
    }
    for ( let i = 0; i < t.length; i++) {
        let val = map.get(t[i])
        if (val === 0 || val === undefined) {
            return t[i]
        } else {
            map.set(t[i], val - 1)
        }
    }
};
```

