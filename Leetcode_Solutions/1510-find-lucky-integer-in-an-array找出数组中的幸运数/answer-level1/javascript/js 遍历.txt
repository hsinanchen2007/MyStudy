### 解题思路
 * 输出来所有的数，然后排序，倒序检测

### 代码

```javascript
/**
 * 输出来所有的数，然后排序，倒序检测
 * key === value
 * @param {number[]} arr
 * @return {number}
 */
var findLucky = function(arr) {
    let list = [];
    list.length = 500;
    list.fill(0);
    for(let e of arr) {
        list[e] += 1;
    }
    for(let i = list.length - 1; i > 0; i--){
        if(list[i] === i) return i;
    }

    return -1;
};
```