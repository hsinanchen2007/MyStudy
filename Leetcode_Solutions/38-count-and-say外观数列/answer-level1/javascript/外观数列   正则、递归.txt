### 解题思路
正则 、 递归

### 代码

```javascript
/**
 * @param {number} n
 * @return {string}
 */

// 正则
// var countAndSay = function(n) {
//     let str = '1'
//     for( let i = 1; i < n; i++ ){
//         str = str.replace( /(\d)\1*/g, item=> `${item.length}${item[0]}`)
//     }
//     return str
// };

//  ------------分割线-------------

// 递归 
var countAndSay = function(n) {
    let str = '1'
    for( let i=1; i<n; i++){
        str = handleSay(str)
    }
    return str
};
var handleSay = function(str) {
    let arr = []
    for( let i=0; i < str.length; i++){
        const s = str[i], last = arr.length-1
        if( !arr[last] || arr[last].indexOf(s) == -1 ) arr.push(s)
        else arr[last] += s
    }
    return arr.map(item=>{
        return `${item.length}${item[0]}`
    }).join('')
};
```