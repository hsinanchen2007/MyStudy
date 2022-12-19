### 解题思路
思路很简单，将字符串s1与自身拼接，如果s2在拼接后的字符串中，就哦了

### 代码

```javascript
/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var isFlipedString = function(s1, s2) {
    if(s1.length!=s2.length){return false}
    if(s1===s2){return true}
    let str = s1.repeat(2)
    let arr = str.split(s2)
    if(arr.length==2){
        return true
    }else{
        return false
    }
};
```