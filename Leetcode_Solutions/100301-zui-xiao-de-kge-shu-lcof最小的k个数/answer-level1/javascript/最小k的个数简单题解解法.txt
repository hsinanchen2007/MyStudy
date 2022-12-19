通过将数组从小到大排序，然后截取数组

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    // 通过排序将数组从小到大排列
    arr.sort(function(vals,valss){
        return vals-valss;
    })
// 截取数组长度为k位
    arr.length = k;
// 返回截取后的数组
    return arr;
};
```