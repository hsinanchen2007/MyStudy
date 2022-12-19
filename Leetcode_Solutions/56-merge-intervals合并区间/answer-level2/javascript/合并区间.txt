```
/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    intervals.sort((a, b) => Math.max(a[0], a[1]) - Math.max(b[0], b[1]))
    for(let i = intervals.length - 2; i >= 0; i--) {
        if (intervals[i + 1][0] <= intervals[i][1]) {
            let tmp = [Math.min(intervals[i][0], intervals[i + 1][0]), Math.max(intervals[i][1], intervals[i + 1][1])]
            intervals.splice(i,2, tmp)
        }
    }
    return intervals
};
```
