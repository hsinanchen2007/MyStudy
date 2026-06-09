### 解题思路
两两比较查找重叠区间，重叠区间再跟下一个元素比较从而获取到最终的可射箭数目

### 代码

```javascript
const findMinArrowShots = points=> {
    points.sort((a,b)=>a[0]-b[0]);
    // console.info(points);
    for(let i=0;i<points.length-1;i++){
        // 按照题意打到边也算射中
        if (points[i][1]>=points[i+1][0]){
            points[i][0]=Math.max(points[i][0],points[i+1][0]);
            points[i][1]=Math.min(points[i][1],points[i+1][1]);
            points.splice(i+1,1);
            i--;
        }
    }
    // console.info(points);
    return points.length;
};
```