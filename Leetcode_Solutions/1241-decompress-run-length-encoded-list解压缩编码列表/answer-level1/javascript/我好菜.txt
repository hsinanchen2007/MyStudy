### 解题思路
暴力填充，我好菜

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var decompressRLElist = function(arr) {
    let newArr = [];
    for(let i =0;i<arr.length;i+=2) {
        for(let j=0;j<arr[i];j++) {
            newArr.push(arr[i+1]);
        }
    }
    return newArr
};
```