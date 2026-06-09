### 解题思路
从后向前遍历, 同时记录当前遇到过的最大值

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number[]}
 */
var replaceElements = function(arr) {
    let val = -1, tmp = -1
    for(let i = arr.length - 1; i >=0 ; i--){
        tmp = val
        if(arr[i] > val){
            val = arr[i]
        }
        arr[i] = tmp
    }
    return arr
};
```