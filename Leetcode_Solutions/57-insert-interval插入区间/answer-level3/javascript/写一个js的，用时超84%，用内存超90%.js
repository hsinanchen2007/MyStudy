```javascript []
/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(intervals, newInterval) {
    let left = newInterval[0];
    let right = newInterval[1];
    let i = 0;
    for (;i<intervals.length;){
        if (newInterval[0] > intervals[i][1]){
            i++;
            continue;
        }
        if (newInterval[1] < intervals[i][0])break;
        left = Math.min(left,intervals[i][0]);
        right = Math.max(right,intervals[i][1]);
        intervals.splice(i,1);
        
    }
    intervals.splice(i,0,[left,right]);
    return intervals
};
```

