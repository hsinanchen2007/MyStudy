### 解题思路
**如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警** 由此可见有奇数和偶数的两种简单路径。
所以简单case下，比较奇数和和偶数和，即如何最大化。
但是最优解不一定是纯奇数和或者偶数和的情况。
例如
#### 纯奇偶数的情况
nums = [1,2,3,4]
*奇数： 1+3=4*
*偶数： 2+4=6*
所以max是偶数case
#### 奇偶数混合的情况
nums = [1,3,1,3,100]
*奇数：1+1    + 100*
*偶数： 3 + 3*
有以上的过程可见「并不是所有的纯奇或偶数是最优解」， 所有可以将「最优奇数」和「最优偶数」相加。
*偶数+奇数： 3（偶数部分）+100（奇数）*

所以每次遍历数字的时候，都比较当前最大的是奇数还是偶数：
```
sumEven = Math.max(sumOdd, sumEven)
```
```
sumOdd = Math.max(sumOdd, sumEven)
```
以上就是分别在奇数和偶数的情况下，「判断和现在最优解」再继续向后求解。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
  
  let sumEven = 0
  let sumOdd = 0
  for(let i= 0; i < nums.length; i++) {
    if(i%2 == 0) {
      sumEven += nums[i];
      sumEven = Math.max(sumOdd, sumEven)
    } else {
      sumOdd += nums[i]
      sumOdd = Math.max(sumOdd, sumEven)
    }
  }
  return Math.max(sumOdd, sumEven)
};
```