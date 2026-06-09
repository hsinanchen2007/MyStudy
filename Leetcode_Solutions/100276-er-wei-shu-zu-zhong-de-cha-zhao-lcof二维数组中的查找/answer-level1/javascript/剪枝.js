### 解题思路
剪枝，每个问题可分为四个子问题，在每个问题上可通过左上角和右上角的值快速判断是否剪除该子问题的解空间。

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    let array = matrix;
    let leny = array.length;
    if(!leny)return false;
    let lenx = array[0].length;
    if(!lenx)return false;

    
    function find1(startx,starty,endx, endy){
        if(endx<startx || endy<starty)return false;
        if(startx==endx && starty == endy ){
            if(array[starty][startx]==target)return true;
            else return false;
        }
       
        if(array[starty][startx]>target || array[endy][endx]<target){
       
            return false;
        }
        
        let midx = ~~((endx-startx)/2);
        let midy = ~~((endy-starty)/2);
        
      return  (find1(startx,starty,startx+midx, starty+midy) || find1(startx+midx+1, starty, endx , starty+midy) || find1(startx ,starty+midy+1 , startx+midx , endy) || find1(startx+midx+1,starty+midy+1,endx , endy));
    }
    
    return find1(0 , 0 ,lenx-1, leny-1);
};
```