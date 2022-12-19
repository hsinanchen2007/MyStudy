### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var multiply = function(num1, num2) {
    let result = [];
    let len1 = num1.length;
    let len2 = num2.length;
    for (let i=0; i< len1 + len2;i++) {
        result[i] = 0;
    }
    const addOnIndex = (val, idx) => {
        let newVal = result[idx] + val;
        if (newVal > 9) {
            addOnIndex(Math.floor(newVal/10), idx+1);
            newVal = newVal % 10;
        }
        result[idx] = newVal;
    }
    num1 = num1.split('').reverse();
    num2 = num2.split('').reverse();
    for (let i=0; i<len1;i++) {
        for (let j=0; j<len2; j++) {
            let val = num1[i] * num2[j];
            if (val > 9) {
                addOnIndex(Math.floor(val/10), i + j + 1);
                val = val % 10;
            } 
            addOnIndex(val, i+j);
        }
    }
    result = result.reverse();
    while(result[0] === 0 && result.length > 1) {
        result.shift();
    }
    return result.join('');
};
```