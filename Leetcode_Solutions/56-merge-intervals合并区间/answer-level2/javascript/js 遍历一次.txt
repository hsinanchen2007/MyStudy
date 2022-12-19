![image.png](https://pic.leetcode-cn.com/4b1b19d3f4f2afa86e32e2cac2da482bf374dd259b3158c3c05c02c710e17fce-image.png)

思路：
    1. 处理特殊情况
    2. 按照每个数组的索引0位置的数字进行从小到大排序
    3. 从0遍历到len - 1的位置，假设当前数组为left，下一个数组为right，
      - 比较left[1] >= right[0]，如果满足这个条件，那么让right = 合并后的区间，
      - 如果不满足条件，那么把left添加进结果集中
    4. 因为只遍历到len - 1，而且遍历的过程中我们只是按条件push( left )，所以不管最后一次的遍历有没有合并区间，我们都需要把最后一个区间push进来
```
var merge = function(intervals) {
  if ( intervals.length === 0 ) return [];
  if ( intervals.length === 1 ) return intervals;
  
  let result = [], i = 0, len = intervals.length;
  intervals.sort( (a,b) => { return a[0] - b[0] } );
  for ( ; i < len - 1; i++ ) {
    let left = intervals[i],
        right = intervals[i + 1];
    if ( left[1] >= right[0] ) {
      intervals[i+1] = [left[0], Math.max( left[1], right[1] )];
    }
    else {
      result.push( left );
    }
  }
  result.push( intervals[len - 1] ); // 因为只遍历到len - 1, 所以要把最后一个数组push进来
  return result;
};
```
