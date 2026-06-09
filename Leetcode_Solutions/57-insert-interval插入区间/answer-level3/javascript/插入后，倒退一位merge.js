### 解题思路
 * 和leetcode-56有点类似，可以采用插入后倒退一位进行merge:
 * 其中index不必须
### 代码

```javascript
const insert = (intervals, newInterval)=>{
    if(intervals.length===0) return [newInterval];
    let index=0,len=intervals.length;
    for(let i=0;i<intervals.length;i++){
        if(intervals[i][0]>=newInterval[0]){
            intervals.splice(i,0,newInterval);
            index=i;
            break;
        }
    }
    if(intervals.length===len){
        intervals.push(newInterval);
        index=intervals.length-1;
    }
    // console.info(index,intervals);
    for(let i=index-1<=0?0:index-1;i<intervals.length-1;i++){
        if(intervals[i+1][0]<=intervals[i][1]){
            intervals[i][1]=Math.max(intervals[i][1],intervals[i+1][1]);
            intervals.splice(i+1,1);
            i--;
        }
    }
    return intervals;
};
```