一次排序，一次遍历 时间复杂度 nlogn

`/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    if (intervals.length <= 1) { return intervals }
    let result = [];
    let isOK = function(a, b) {
        if (a[0] >= b[0] && a[0] <= b[1]) { return true }
        if (a[1] >= b[0] && a[1] <= b[1]) { return true }
        if (a[0] <= b[0] && a[1] >= b[1]) { return true }
        if (a[0] >= b[0] && a[1] <= b[1]) { return true }
        return false
    }
    let mergeInternal = function(a, b) {
        let min = Math.min(a[0],b[0])
        let max = Math.max(a[1], b[1]);
        return [min, max]
    }
    intervals.sort((a, b) => a[0] < b[0] ? -1: 1)
    let len = intervals.length
    for(let i = 0; i < len - 1;) {
        let c = intervals[i];
        let next = intervals[i+1];
        if (c == null || next == null) {
            break;
        }
        if (isOK(c, next)) {
            intervals.splice(i, 1)
            intervals[i] = mergeInternal(c, next)
        } else {
            i++
        }
    }
    return intervals
};`