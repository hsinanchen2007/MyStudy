### 解题思路
* 数组从小到大排序：sort()
* 获取新数组前k个值，slice() 方法返回一个新的数组对象（包括 begin，不包括end）

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    const new_arr = arr.sort((a,b) => a - b);
    return new_arr.slice(0, k)
};
```