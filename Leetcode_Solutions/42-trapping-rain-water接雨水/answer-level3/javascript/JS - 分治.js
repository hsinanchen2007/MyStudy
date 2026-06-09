### 解题思路
如题

### 代码

```javascript
/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    // 分治
    // 问题可以拆解为两个最高边界内的接水量
    return trapWithLimit(height, 0, 0);
};

// 寻找数组最大的那一项[index,val]
const findHighest = (arr) => arr.reduce((pre, curr, idx) => {
    if (!pre || curr > pre[1]) {
        return [idx, curr];
    } else {
        return pre;
    }
}, [0, arr[0]]);
// 按高度计算储水
const clacWater = (arr, high) => arr.reduce((pre, curr) => (high - curr + pre), 0);
// 获取两个边界内的接水量
const trapWithLimit = (arr, leftLimit, rightLimit) => {
    // 取数组内最高点
    let highest = findHighest(arr);
    console.log(highest);
    if (highest[1] <= leftLimit && highest[1] <= rightLimit) {
        return clacWater(arr, Math.min(leftLimit, rightLimit));
    }
    let rightArr = arr.splice(highest[0]+1);
    let leftArr = arr.splice(0, highest[0]);
    let leftWater = 0;
    let rightWater = 0;
    if (leftArr.length) {
        leftWater = leftLimit >=  highest[1] ? clacWater(leftArr, highest[1]) : trapWithLimit(leftArr, leftLimit, highest[1]);
    }
    if (rightArr.length) {
        rightWater = rightLimit >= highest[1] ? clacWater(rightArr, highest[1]) : trapWithLimit(rightArr, highest[1], rightLimit);
    }
    return leftWater + rightWater;
}
```