### 解题思路
![image.png](https://pic.leetcode-cn.com/51400ae32e7d6b0ef4caad62fdf32b7751af4980d47890f82483c0f375fb06ca-image.png)

- 判断两个点的 height 和 width， 取较大值；

### 代码

```javascript
/**
 * @param {number[][]} points
 * @return {number}
 */
 var minTimeToVisitAllPoints = function(points) {
    let count = 0
    debugger;
    for(let i = 1; i < points.length; i++){
        let height = Math.abs(points[i][1]-points[i-1][1])
        let width = Math.abs(points[i][0]-points[i-1][0])
        if( height/width == 1){
            count += height
        }
        if( height/width > 1){
            count += height
        }
        if( height/width <1){
            count += width
        }
    }
    // debugger;
    return count
};
```

