### 解题思路
将abba转成1221，使用map，若是之前出现过，取该词对应的数，没出现过，则新加数。
两个都进行转化，看最后是否一样。

### 代码

```javascript
/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function(pattern, str) {
    const getSame = function(str,flag){
        let arr = flag ? str.split(' ') : str.split('');
        let sameStr = '';
        let j = 1;
        let map = new Map();
        for(let item of arr){
            let i = map.has(item) ? map.get(item) : j;
            sameStr = sameStr.toString() + i;
            map.set(item,j++);
        }
        return sameStr;
    }
    return getSame(pattern) === getSame(str,true);
};
```