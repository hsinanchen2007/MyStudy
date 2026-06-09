### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    let store = {
        2: ['a', 'b', 'c'],
        3: ['d', 'e', 'f'],
        4: ['g', 'h', 'i'],
        5: ['j', 'k' ,'l'],
        6: ['m', 'n', 'o'],
        7: ['p', 'q', 'r', 's'],
        8: ['t', 'u', 'v'],
        9: ['w', 'x', 'y', 'z']
    }
     if (!digits) return [];
    if (digits.length === 1) return store[digits];
    let arr = [], res= []
    for (let i = 0; i < digits.length; i++) {
        arr.push(store[digits[i]]);
    }
    let results = [], result = [];
    doExchange(arr, 0);
    function doExchange(arr, index){
        for (var i = 0; i<arr[index].length; i++) {
            result[index] = arr[index][i];
            if (index != arr.length - 1) {
                doExchange(arr, index + 1)
            } else {
                results.push(result.join(''))
            }
        }
    }

      return results;
};
```