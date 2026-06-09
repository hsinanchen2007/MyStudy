借鉴了[@jarrychung](/u/jarrychung/)大神的解题思路，大神题解移步[三下五除二](https://leetcode-cn.com/problems/construct-the-rectangle/solution/san-xia-wu-chu-er-by-jarrychung/)

正方形边长为Math.sqrt(area)，因为是长方形，宽最大为Math.sqrt(area)
所以当满足长*宽==面积并且长>=宽，就选取第一个(宽是最大的，长宽差肯定最小)

### 代码

```javascript
/**
 * @param {number} area
 * @return {number[]}
 */
var constructRectangle = function(area) {
    let w = Math.floor(Math.sqrt(area));;
    while(w>0){
        let l = Math.floor(area/w);
        if(l*w==area&&l>=w) return[l,w];
        w--;
    }
};
```