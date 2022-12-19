### 解题思路
由于题目要求按照指定的点顺序计算时间，实际上就是可以拆分为对个两点之间最短时间的问题，
两点之间其实就是线段最短，比如两个点是（0，0）和（3，3），那么直接就是斜线经过（1，1），（2，2）最短，
现在如果把后一个点改为（3，4），现在是长方形，实际最短的方案就变成了先去（3，3），然后再用长边减去短边即可。
所以一下代码中，直接按照长方形处理（正方形是特殊的长方形）

### 代码

```javascript
/**
 * @param {number[][]} points
 * @return {number}
 */
var minTimeToVisitAllPoints = function(points) {
    let result = 0;
   /**
    * @return {number}
    */
   function WithTwoPoints(pointA,pointB) {
       let x  =  Math.abs(pointA[0]-pointB[0]);
       let y  =  Math.abs(pointA[1]-pointB[1]);
       return Math.min.apply(Math, [x, y]) + Math.abs(x - y); //把正方形部分和差值相加
   }
   for(var i=0;i<points.length-1;i++){
       result = result + WithTwoPoints(points[i],points[i+1])
   }
   return result;
};
```