### 解题思路
加个结束标志挺省事的
转数组直接shift() 当然直接for循环也一个效果

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    var out = ''
    var count = 1
    var arr = Array.from(S + '%')
    var last = arr.shift()
    while(arr.length > 0){
        var now = arr.shift()
        if (now !== last){
            out += last + count.toString()
            last = now
            count = 1
        } else {
            count ++
        }
    }
    return out.length < S.length ? out : S
};
```