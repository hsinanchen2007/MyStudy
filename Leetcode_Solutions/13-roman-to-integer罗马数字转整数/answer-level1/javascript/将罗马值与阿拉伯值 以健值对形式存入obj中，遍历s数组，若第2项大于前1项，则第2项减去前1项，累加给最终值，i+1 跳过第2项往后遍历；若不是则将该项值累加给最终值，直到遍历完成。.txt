### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    let obj = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    };
    let res = 0;
    let sArr = s.split('');
    for(let i =0; i< sArr.length;i++){
        if(obj[sArr[i+1]] > obj[sArr[i]]){
            res += obj[sArr[i+1]] - obj[sArr[i]];
            i++ ;
        }else {
            res += obj[sArr[i]]
        }
    }
    return res;
};
```