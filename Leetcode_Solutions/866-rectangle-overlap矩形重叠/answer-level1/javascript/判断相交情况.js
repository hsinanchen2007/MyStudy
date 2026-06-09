### 解题思路
以第一个参数的矩形的左下角建立坐标系，第二个矩形的坐下角可能在四个象限，分别判断每个象限情况相交的情况即可。

### 代码

```javascript
/**
 * @param {number[]} rec1
 * @param {number[]} rec2
 * @return {boolean}
 */
var isRectangleOverlap = function(rec1, rec2) {
            if(rec1[0] <= rec2[0] && rec1[1] <= rec2[1]){ //第一象限
                if(rec1[2] > rec2[0] && rec1[3] > rec2[1]){
                    return true;
                }
            }
            if(rec1[0] < rec2[0] && rec1[1] > rec2[1]){ //第二象限
                if(rec1[3] > rec2[0] && rec1[1] < rec2[3]){
                    return true
                }
            }
            if(rec1[0] >= rec2[0] && rec1[1] >= rec2[1]){ //第三象限
                if(rec1[0] < rec2[2] && rec1[1] < rec2[3]){
                    return true
                }
            }
            if(rec1[0] > rec2[0] && rec1[1] < rec2[1]){ //第四象限
                if(rec1[0] < rec2[3] && rec1[3] > rec2[1]){
                    return true
                }
            }
            return false

};
```