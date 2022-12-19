更新一下： 当平均值 eq 为 0 的时候确实 count 可能不止 3 因为 0 的倍数可能也是 0

思路：**三个值相等即这个值为数组和的三分之一**

例如 [0,2,1,-6,6,-7,9,1,2,0,1]
平均值为 3 ,我们开始遍历数组求子项和
第一个和为 0
第二个和为 0 + 2 = 2
第三个和为 0 + 2 + 1 = 3 与平均值相等，我们得到第一个数组
第四个和我们回到0开始 -6 
第五个和 -6 + 6 = 0
第六个 。。。
如此类推，当 count 等于 3 的时候就可以得到 true 的结果了，否则遍历完整个数组 count 都小于 3，返回 false。
可能你会想到 如果没有遍历完 count 就已经等于 3 呢，不用怕，因为如果 count 等于三之后，后面还有项的话，他们的和肯定是等于0。可以归到第三部分去。
```javascript
/*
 * @lc app=leetcode.cn id=1013 lang=javascript
 *
 * [1013] 将数组分成和相等的三个部分
 */
/**
 * @param {number[]} A
 * @return {boolean}
 */
var canThreePartsEqualSum = function(A) {
  // 先求数组的三分之一是多少
  let eq = A.sum() / 3;  
  let count = 0
  let s = 0
  // 遍历数组 当相加的数等于三分之一值的时候 做一次切割
  for(let i of A){
    s += i
    if(s === eq){
      count++
      s = 0
    }
  }
  if (eq === 0 && count > 3) return true 
  return count === 3
};
Array.prototype.sum = function () { // 定义求数组和方法
  return this.reduce((a, b) => a + b, 0)
}
```