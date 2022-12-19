### 解题思路

通过双指针依次去对比删除。

### 代码

```javascript
/**
 * @param {number[][]} intervals
 * @return {number}
 */
var removeCoveredIntervals = function(intervals) {
    let { length } = intervals;
    for(let i = 0, j = length - 1; i < length; i++){
        while(j >= 0 && j != i){
            if(intervals[j][0] <= intervals[i][0] && intervals[j][1] >= intervals[i][1]){
                intervals.splice(i, 1);
                i -= 1;
                length = intervals.length;
                break;
            }else if(intervals[j][0] >= intervals[i][0] && intervals[j][1] <= intervals[i][1]){
                intervals.splice(j, 1);
                length = intervals.length;
            }
            j--;
        }
        j = length - 1;
    }
    return intervals.length;
};
```