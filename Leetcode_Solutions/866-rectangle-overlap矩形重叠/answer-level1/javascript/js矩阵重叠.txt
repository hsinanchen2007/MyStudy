### 解题思路
判断x中是否有交集，判断y轴是否有交集，两个轴同时有交集则表示矩阵有重叠

### 代码

```javascript
/**
 * @param {number[]} rec1
 * @param {number[]} rec2
 * @return {boolean}
 */
var isRectangleOverlap = function(rec1, rec2) {
    
    function ismix(x1,x2,x3,x4){
        let min1=Math.min(x1,x2);
        let max1=Math.max(x1,x2);

        let min2=Math.min(x3,x4);
        let max2=Math.max(x3,x4);

        if(min1>=max2 ||max1<=min2)return false;
        return true;
    }
    return ismix(rec1[0],rec1[2],rec2[0],rec2[2]) && ismix(rec1[1],rec1[3],rec2[1],rec2[3]);
    
    
};
```