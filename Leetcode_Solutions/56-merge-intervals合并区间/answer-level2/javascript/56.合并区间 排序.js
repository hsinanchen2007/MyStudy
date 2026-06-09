### 解题思路
1.按一维数组中第0个元素由小到大排序
2.合并

### 代码

```javascript
/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
  if (intervals.length===0 || intervals.length===1) {
    return intervals;
  }
  let sortlist = intervals.sort((n1,n2) => n1[0]-n2[0]);
  let resultlist = [sortlist[0]];
  for (let i=1;i<sortlist.length;i++) {
     let length = resultlist.length;
     if (sortlist[i][0]<=resultlist[length-1][1]) {
       if (sortlist[i][1]>resultlist[length-1][1]) {
         resultlist[length-1][1] = sortlist[i][1];          
       } 
     }else {
       resultlist.push(sortlist[i]);
     }
  }
  return resultlist;
};
```