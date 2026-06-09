### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} array
 * @return {number[]}
 */
var subSort = function (array) {
    if(array.length <= 1) return [-1, -1]
    let arr = [].concat(array),
        index = [],
        count = 0;
    array.sort((a, b) => a - b);
    for (let i = 0; i < array.length; i++) {
        if (arr[i] != array[i]) {
            index.push(i)
        } else {
            count++;
        }
    }
    if(count === array.length) return [-1,-1]
    return [index[0], index[index.length - 1]]

};
```