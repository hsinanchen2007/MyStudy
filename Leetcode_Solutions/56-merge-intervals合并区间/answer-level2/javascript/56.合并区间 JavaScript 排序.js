### 解题思路
使用快排排序，然后遍历一次，根据判断把被前一个区间包含的区间弹出，否则就继续判断下一个

### 代码

```javascript
/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    var i,j;
    intervals.sort((a,b)=>(a[0]-b[0]))
    i=1;
    while (i<intervals.length){
        if (intervals[i][0]>=intervals[i-1][0]&&intervals[i][0]<=intervals[i-1][1]){
            if (intervals[i-1][1]<=intervals[i][1]){
                intervals[i-1][1]=intervals[i][1]
                intervals.splice(i,1)
            }
            else if (intervals[i-1][1]>intervals[i][1]){
                intervals.splice(i,1)
            }
        }
        else i++
    }
    return intervals;
};
```