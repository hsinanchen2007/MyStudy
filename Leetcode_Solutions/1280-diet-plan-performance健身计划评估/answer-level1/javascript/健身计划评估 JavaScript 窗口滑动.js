``` javascript
/*
 * @lc app=leetcode.cn id=1176 lang=javascript
 *
 * [1176] 健身计划评估
 */
/**
 * @param {number[]} calories
 * @param {number} k
 * @param {number} lower
 * @param {number} upper
 * @return {number}
 */
var dietPlanPerformance = function(calories, k, lower, upper) {
  let goal = 0 // 得分
  let i = 0
  let sum = 0
  if(k >= calories.length){ // 如果窗口比总长长 用总和对比
    sum = calories.reduce((sum, ele) => sum + ele, 0)
    return sum > upper ?  1 : (sum < lower ? -1 : 0)
  }
  while(i < calories.length){
    sum = sum + calories[i]
    if(i >= k){
      sum = sum - calories[i - k]
    }
    if(i + 1>= k){
      if(sum<lower) goal--
      else if(sum>upper) goal++
    }
    i++
  }
  return goal
};
// ✔ Accepted
//   ✔ 27/27 cases passed (72 ms)
//   ✔ Your runtime beats 100 % of javascript submissions
//   ✔ Your memory usage beats 100 % of javascript submissions (39.7 MB)
```