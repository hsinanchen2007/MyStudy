### 解题思路
- 将数组按照左边界升序，右边界降序排列
- 显然后面所有左边界和它一样的区间都将被删除
- 直到找到第一个右区间大于它的即可，再以该区间为起点比较即可

### 代码
```javascript
var removeCoveredIntervals = function(intervals) {
    // [x, y]按照x升序 y降序排列
    intervals.sort((a, b) => {
        if (a[0] == b[0]) {
            return b[1] - a[1];
        }
        return a[0] - b[0];
    });
    let i = 0, len = intervals.length, cut = 0;

    while (i < len) {
        let [m, n] = intervals[i], j = i + 1;

        while (j < len && m <= intervals[j][0] && n >= intervals[j][1]) {
            cut++;
            j++;
        }
        i = j;
    }
    return len - cut;
};
```