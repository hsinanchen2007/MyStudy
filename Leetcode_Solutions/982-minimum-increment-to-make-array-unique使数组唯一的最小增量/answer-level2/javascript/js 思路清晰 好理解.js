// ![image.png](https://pic.leetcode-cn.com/10510826729bca3b0f294be194f1ec2f9a7f54c5832ebba946a7d2e49c96e3f4-image.png)

// ### 解题思路
// ```js
  思路：
  
  让每一个数都不同，那么先求出数组中最小的数是多少，再根据数组的长度来判断出
  要想让数组成为最小增量的目标数组，对照着每一个位置去计算操作数
  
  比如案例：
  
  [3,2,1,2,1,7]
  
  最小值是 1，一共有 6 个数，那么理想状态下，是数组通过增量操作变成 [1,2,3,4,5,6]
  
  👇下面是核心逻辑：
  
  先把原始数组排序，这样和目标数组一样都是升序，好对比
  
  [1,1,2,2,3,7] + [10, 15]
  [1,2,3,4,5,6] + [8 , 11]
  
  第 1 位：一样，操作数 0
  第 2 位：不一样，操作数 1
  第 3 位：不一样，操作数 1
  第 4 位：不一样，操作数 2
  第 5 位：不一样，操作数 2
  第 6 位：特殊情况，不需要操作 操作数 0，注意：如果后面还有数的话，要从
  8(7 + 1) 开始继续进行比较，看上面的 "+" 后面，下一次比较 8 和 10，同样
  不需要操作，并且原数组的数 10 大于 8，那么下一比较从 11(10 + 1) 开始
// ```

// ### 代码

// ```javascript
/**
 * @param {number[]} A
 * @return {number}
 */

var minIncrementForUnique = function(A) {
  A.sort((a, b) => a - b);
  
  let min = Math.min(...A),
      n = A.length,
      larger = min + n - 1,
      handles = 0,
      start = min;
  
  for (let i = 0; i < n; i++) {
    let c = A[i];
    if (c <= start) {
      handles += (start - c);
      start++;
    } else {
      start = c + 1;
    }
  }
  
  return handles;
};
// ```