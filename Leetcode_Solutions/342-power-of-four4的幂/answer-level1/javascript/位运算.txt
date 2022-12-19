### 解题思路
![屏幕快照 2020-03-06 上午11.15.22.png](https://pic.leetcode-cn.com/b13c4bcb6ec07accd07e56213334232a1f9956dfb2c75297ccb872ec126163c3-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-06%20%E4%B8%8A%E5%8D%8811.15.22.png)
### 代码

```javascript
/**
 * @param {number} num
 * @return {boolean}
 */
var isPowerOfFour = function(num) {
    if(num>0){
        if((num&(num-1))==0){
            if((num & 0x55555555) == num){
                return true;
            }
        }
    }
    return false;
};
```