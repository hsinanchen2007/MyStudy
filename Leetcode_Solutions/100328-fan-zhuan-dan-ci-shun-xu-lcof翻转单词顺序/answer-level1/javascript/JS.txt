### 解题思路


### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let arr = s.split(" ");
    let reverseArr = [];
    let trimArr = arr.filter(function(element){
        return element != "";
    })
    for (let i = trimArr.length - 1; i >= 0; i--){
        reverseArr.push(trimArr[i]);
    }
    return reverseArr.join(" ");
};
```