### 解题思路
1 只是分隔的作用，所以只分析连续的 0  就可以。
先join,再split，这里牺牲了效率 ，不过可读性好。直接就获得了0的分组（如果是追求效率，可以换成一次迭代，在迭代中对0分组处理。）

对0 的分组 分三种情况，头，中，尾
头和尾，0的长度就是最大距离
中间的，如果是偶数` lenth/2`，如果是奇数，`length+1/2`


### 代码

```javascript
/**
 * @param {number[]} seats
 * @return {number}
 */
var maxDistToClosest = function(seats) {
  let list = seats.join('').split('1')
  let max = list[0].length
  for (let i = 1; i<list.length-1; i++) { 
    let item = list[i]
    if (item.length % 2) { 
      max=Math.max(max,(item.length+1)/2)
    }
    else {
      max=Math.max(max,(item.length/2))
    }
  } 
  let last = list[list.length - 1]
  max = Math.max(last.length, max)
  return max
};
```