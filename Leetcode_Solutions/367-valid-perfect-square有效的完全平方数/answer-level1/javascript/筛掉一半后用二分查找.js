### 解题思路
第一次可以直接先筛掉一半, 正整数开方,肯定是小于等于它的一半, 然后再用二分查找

### 代码

```javascript
/**
 * @param {number} num
 * @return {boolean}
 */
var isPerfectSquare = function(num) {
    let l = 0
    let r = (num>>1) + 1
    while(l<=r){
      let mid = (l + r)>>1
      let res = mid * mid
      if(res == num){
        return true
      }else if(res<num){
        l = mid + 1
      }else{
        r = mid - 1
      }
    }
    return false
};
```