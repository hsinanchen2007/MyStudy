其实我们可以把题目理解成顺时针走 起点到终点的距离和从终点到起点的距离谁更近一点

ps. 不过测试用例里遇到了 [7,10,1,12,11,14,5,0],7,2 这种起点在数组里的位置比终点位置还远的情况 所以如果有这种情况 让终点跟起点互换就行

``` javascript
/*
 * @lc app=leetcode.cn id=1184 lang=javascript
 *
 * [1184] 公交站间的距离
 */
/**
 * @param {number[]} distance
 * @param {number} start
 * @param {number} destination
 * @return {number}
 */
var distanceBetweenBusStops = function(distance, start, destination) {
    let sum = 0
    let sum2 = 0
    if(start > destination){ // 判断哪个是起点
      let a = start
      start = destination
      destination = a
    }
    for(let i in distance){
      if(i<start){
        sum2 = sum2 + distance[i]
      } else if (i >= destination) {
        sum2 = sum2 + distance[i]
      } else {
        sum = sum + distance[i]
      }
    }
    return Math.min(sum, sum2)
};
// ✔ Accepted
//   ✔ 37/37 cases passed (68 ms)
//   ✔ Your runtime beats 92.5 % of javascript submissions
//   ✔ Your memory usage beats 100 % of javascript submissions (35.9 MB)
```