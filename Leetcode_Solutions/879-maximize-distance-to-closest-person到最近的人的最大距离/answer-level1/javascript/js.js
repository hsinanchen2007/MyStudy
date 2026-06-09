
### 代码

```javascript
/**
 * @param {number[]} seats
 * @return {number}
 */
var maxDistToClosest = function(seats) {
  let ind1_arr = []  // 定义一个变量存1的坐标
  let len = seats.length
  for (let i = 0; i < len; i++) {
    if(seats[i]===1){
      ind1_arr.push(i)
    }
  }
  // console.log('ind1_arr:',ind1_arr)
  let max_gap = 0
  let len2 = ind1_arr.length
  for (let i = 1; i < len2; i++) {
    // 每两个相邻坐标计算，找到最大间隔
    max_gap = Math.max(ind1_arr[i]-ind1_arr[i-1] , max_gap)
  }
  // console.log('max_gap:',max_gap)
  let max1 = Math.floor(max_gap/2)
  let max2 = len - ind1_arr[ind1_arr.length - 1] - 1 // 放到最后时的间隔
  let max3 = ind1_arr[0] // 放在最开始时的间隔
  return Math.max(max1,max2,max3) // 比较找到最大间隔
};
```