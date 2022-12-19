### 解题思路
1. 先按开始时间从小往大排序
2. 比较 前者结束时间 一旦和后者开始时间有交叉重点 就表示不能全部能参加；

### 代码

```javascript
var canAttendMeetings = function(intervals) {
    //按开始时间排
    intervals.sort(function(a,b){ return a[0] - b[0];})
    //前者结束时间 一旦和后者开始时间有交叉重点 就表示不能全部能参加；
    for(var i=0;i<intervals.length-1;i++){
        if(intervals[i][1]>intervals[i+1][0]){
            return false;
        }
    }
    return true;
};
```