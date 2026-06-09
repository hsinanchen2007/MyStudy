### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var multiply = function(str1, str2) {
    if (!Number(str1) || !Number(str2)) return '0'
    let res = []
    for (let i = 0; i < str1.length; i++) {
       let i_temp = str1[i]
       for (let j = 0; j < str2.length; j++) {
           let j_temp = str2[j]
           let pow = i + j
           res[pow] = (res[pow] ? res[pow] : 0) + (i_temp * j_temp)
       }
    }
    let decade_val = 0
    let index_res = res.length - 1
    while(index_res >= 0) {
        let val = res[index_res] + decade_val
        res[index_res] = val % 10
        decade_val = val >= 10 ? parseInt(val / 10) : 0 
        if (index_res === 0 && decade_val){
            res.unshift(0)
        } else {
            index_res--
        } 
    }
    return res.join('')
}
```