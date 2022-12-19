![image.png](https://pic.leetcode-cn.com/1a1efdbcf6f150f27602c95d4084330099e44909e987aca4f4e657c108f993d0-image.png)

```
var insert = function(intervals, newInterval) {
    intervals.push(newInterval);
    let curInd = intervals.length - 1;
    let preInd = curInd - 1,
        cur = intervals[curInd];
    while (preInd >= 0 && cur[0] < intervals[preInd][0]) {
        intervals[preInd + 1] = intervals[preInd];
        preInd--;
    }
    intervals[preInd + 1] = cur;

    let res = [];
    res.push(intervals.reduce(function(pre, cur, index, arr) {
        if (pre[1] >= cur[0]) {
            if (pre[1] < cur[1])
                pre[1] = cur[1];
            return pre;
        } else {
            res.push(pre);
            return cur;
        }
    }))
    return res;
};
```
