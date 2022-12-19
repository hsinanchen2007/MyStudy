### 解法一
最大值一定是一组的最后一个元素与另一组第一个元素之间的距离，使用暴力枚举结果

### 代码

```javascript
/**
 * @param {number[][]} arrays
 * @return {number}
 */
var maxDistance = function(arrays) {
    const len = arrays.length
    let maxDistance = -1
    for (let i = 0; i < len; i++) {
        const start = arrays[i][0]
        for (let j = 0; j < len; j++) {
            if (i !== j) {
                const len2 = arrays[j].length
                const end = arrays[j][len2 - 1]
                maxDistance = Math.max(maxDistance, Math.abs(end - start))
            }
        }
    }
    return maxDistance
};
```

### 解法二
使用双指针，分别维护最小值和最大值，一次循环解决

###代码
```javacsript
/**
 * @param {number[][]} arrays
 * @return {number}
 */
var maxDistance = function(arrays) {
    let res = 0, min = arrays[0][0], max = arrays[0][arrays[0].length - 1];
    for (let i = 1; i < arrays.length; i++) {
        res = Math.max(res, Math.max(Math.abs(arrays[i][arrays[i].length - 1] - min), Math.abs(max - arrays[i][0])));
        min = Math.min(min, arrays[i][0]);
        max = Math.max(max, arrays[i][arrays[i].length - 1]);
    }
    return res;
}
```