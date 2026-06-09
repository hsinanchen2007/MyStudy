
```
    /**
    * @param {number[][]} intervals
    * @return {number[][]}
    */

    var merge = function(intervals) {
        if (intervals === null || intervals.length<=1) return intervals
        let res = [], i = 0, l = intervals.length
        intervals.sort((a,b) => a[0]-b[0]) //保证curL一定是左边界
        while(i < l) {
            let curL = intervals[i][0],
                curR = intervals[i][1]
            while(i < l - 1) {
                let next = intervals[i+1]
                if (next[0] <= curR) {
                    curR = Math.max(curR, next[1])
                i++ //这个很重要， 同外层while共用一个i，确保不会重复计算
                } else {
                    break
                }
            }
            res.push([curL, curR])
            i++
        }
        
        return res
    };
```
