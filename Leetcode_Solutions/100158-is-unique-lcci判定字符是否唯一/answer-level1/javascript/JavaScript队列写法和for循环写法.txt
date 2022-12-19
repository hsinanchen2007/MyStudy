### 解题思路
第1种for循环写法；
第2种队列写法，pop()和shift()都可以。
更推荐第2种

### 代码

```javascript
/**
 * @param {string} astr
 * @return {boolean}
 */
var isUnique = function(astr) {
    // for循环解法
    // var length = astr.length;
    // var res = true;
    // var arr = astr.split('');
    // if (length >= 0 && length <= 100) {
    //     for(var i = 0; i < arr.length; i++) {
    //         for(var j = i + 1; j < arr.length; j++) {
    //             console.log(i, j);
    //             if (arr[i] === arr[j]) {
    //                 return res = false;
    //             }
    //         }
    //     }
    // }
    // return res;

    // 队列解法
    var res = true;
    var arr = astr.split('');
    for (var i = 0; i < arr.length; i++) {
        const tmp = arr.pop();
        if (arr.find(i => i === tmp)) {
            return res = false
        }
    }
    return res;
};
```