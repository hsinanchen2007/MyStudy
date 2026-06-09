### 解题思路

正则

### 代码
// 正则
```javascript
/**
 * @param {string} s
 * @return {string}
 */
var freqAlphabets = function(s) {
    return s.replace(/(\d{2}(?=#)\#)|(\d{1})/g, a => String.fromCharCode(parseInt(a) + 96));
};
```

````javascript
// 遍历比较
/**
 * @param {string} s
 * @return {string}
 */
var freqAlphabets = function(s) {
    let result = '';
    const { length } = s;
    for(let i = 0, j; i < length; i++){
        j = i + 2;
        if(s[j] === '#'){
            let value = +`${s[i]}${s[j - 1]}` + 96;
            result += String.fromCharCode(value);
            i = j;
        }else{
            result += String.fromCharCode(+s[i] + 96);
        }
    }
    return result;
};
````