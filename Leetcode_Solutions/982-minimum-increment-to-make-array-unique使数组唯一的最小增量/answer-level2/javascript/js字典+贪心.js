### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var minIncrementForUnique = function(A) {
    let dict = {};
    let output = 0;
    for(let i = 0; i < A.length; i++) {
        if(dict[A[i]]) {
            dict[A[i]]++;
        } else {
            dict[A[i]] = 1;
        }
    }
    let keys = Object.keys(dict);
    keys.sort((a, b) => parseInt(a)-parseInt(b));
    for(let i = 0; i < keys.length-1; i++) {
        //console.log(keys, keys[i], output, dict)
        if(dict[keys[i]] == 1) continue
        if(parseInt(keys[i+1]) - parseInt(keys[i]) - 1 >= dict[keys[i]]-1) {
            output += (1+dict[keys[i]]-1) * (dict[keys[i]]-1) / 2;
        } else {
            output += (1+parseInt(keys[i+1]) - parseInt(keys[i]) - 1)*(parseInt(keys[i+1]) - parseInt(keys[i]) - 1)/2;
            dict[keys[i]] -= (parseInt(keys[i+1]) - parseInt(keys[i]) - 1);
            output += (parseInt(keys[i+1]) - parseInt(keys[i])) * (dict[keys[i]]-1);
            dict[keys[i+1]] += dict[keys[i]]-1;
        }
    }
    if(dict[keys[keys.length-1]] > 1) {
        output += (1+dict[keys[keys.length-1]]-1) * (dict[keys[keys.length-1]]-1) / 2;
    }
    return output;
};
```