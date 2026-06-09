```javascript []
function merge(intervals) {
    if (!intervals.length) return []
    intervals.sort((a, b) => a[0] - b[0])
    let result = intervals.reduce((acc, cur) => {
        let len = acc.length
        if (cur[0] > acc[len - 1][1]) {
            acc = acc.concat([cur])
        } else {
            acc[len - 1][1] = Math.max(acc[len - 1][1], cur[1])
        }
        return acc
    }, [intervals[0]])
    return result
}
```
