// ![image.png](https://pic.leetcode-cn.com/2cc4fdb9749b8dbb72a4ceb59f41d271bb8a09b8af2dbbebd4bf91b0dac33111-image.png)

// ### 解题思路
// ```js
  184ms
  看了题解区竟然没想到倒着推回来？？？
  哭着注释了我的大回溯，我大回溯虽然没过，但思路没毛病 😿
  
  数组中最大的数字一定是由其他几个数字和另一个数字构成的，那么我们可以逆向推理出这个数字
  替换掉当前的最大值，只要数组的最大元素大于1，就一直推理下去
  
  举例：测试用例 [3,5,9]
  1.  9 - (5 + 3) = 1   => [1,3,5]
  2.  5 - (1 + 3) = 1   => [1,1,3]
  3.  3 - (1 + 1) = 1   => [1,1,1] 成立
  
  不成立的条件：数组中出现小于1的数
// ```

// ### 代码

// ```javascript
/**
 * @param {number[]} target
 * @return {boolean}
 */

var isPossible = function(target) {
  target.sort((a, b) => a - b);
  
  while (target[target.length - 1] > 1) {
    let sum = target.reduce((prev, curr) => {
      return prev + curr;
    }, 0);
    sum -= target[target.length - 1];
    target[target.length - 1] = target[target.length - 1] - sum;
    target.sort((a, b) => a - b);
    if (target[0] < 1) break;
  }
  
  return target[target.length - 1] === 1 && target[0] === 1;
}

/*
  回溯法：第28个用例超时
*/
// var isPossible = function(target) {
//   let base = new Array( target.length ).fill(1),
//       ans = false;
  
//   target.sort((a, b) => a - b);
  
//   function dfs(curr, index) {
//     if (ans === true) return ;
    
//     let sum = add( curr );
//     // 如果当前和加起来大于当前的目标值了，返回
//     if (sum > target[index]) return ;
    
//     // 如果等于当前目标值了并且index没到最后一个，index ++，否则找到答案，退出
//     if (sum === target[index]) {
//       if (index === target.length - 1) {
//         // 这里判断当前的某一个值替换为此时的 sum，使得与结果相等，再返回true
//         for (let i = 0; i < curr.length; i++) {
//           let temp = JSON.parse( JSON.stringify( curr ) );
//           temp[i] = sum;
//           temp.sort((a, b) => a - b);
//           if (JSON.stringify( temp ) === JSON.stringify( target )) {
//             ans = true;
//             break;
//           }
//         }
//         if (ans === true) return;
//       } else {
//         index++;
//       }
//     }
    
//     // 遍历
//     for (let i = 0; i < curr.length; i++) {
//       let remember = curr[i];
//       curr[i] = sum;
//       dfs(curr, index);
//       curr[i] = remember;
//     }
//   }
  
//   let start = 0;
//   for (let i = 0; i < target.length; i++) {
//     if (target[i] !== 1) {
//       start = i;
//       break;
//     }
//   }
//   dfs(base, start);
  
//   return ans; 
// };
  
// function add(arr) {
//   let count = arr.reduce((prev, curr) => {
//     return prev + curr;
//   }, 0);
  
//   return count;
// }
// ```