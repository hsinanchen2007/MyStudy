### 解题思路
按照思路 出现次数为偶次的字符可以组成一个回文串，如果出现了奇数次的字符，那就把他的出现偶数次加上，这样的话只要有奇数次字符出现，最后得出结果的时候总数要加上1。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let length = 0
    let arr = s.split('')
    let flag = false
    let obj = {}
    for(let i=0;i<arr.length;i++){
        if(obj.hasOwnProperty(arr[i])){
            obj[arr[i]]++
        } else {
            obj[arr[i]] = 1
        }
    }
    for(let key in obj){
        if(obj[key] % 2 == 0){
            length+=obj[key]
        } else {
            flag = true
            length+=obj[key] -1
        }
    }
    return flag?length + 1: length
};
```
