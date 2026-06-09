// ![image.png](https://pic.leetcode-cn.com/fd6de623a68e0d28237f8fd79a74864bd5c35cb1372f185704979500f718f740-image.png)

// ### 解题思路
// ```js
  动态规划：
  
  dp[i]: 代表前 i 个字符串是否可以由 wordDict 中的单词构成，最终求的肯定是
  dp[s.length]。
  
  核心：怎么判断 dp[i] 是否为符合条件的？
  
  举例：leetcode ["leet", "code"];
  比如dp[5] 也就是 'leetc' 是否可以由 wordDict 中的单词构成
  
  对于dp[5]来说，我们需要从dp[0] 遍历到 dp[5]
  
  - 如果 dp[0] 是 true，并且 s.slice(0, 5) 的字符串可以在 wordDict
    中找到，那么 dp[5] 就是true，下面同理👇
  - dp[1] === true && s.slice(1, 5) in wordRict
  - dp[2] === true && s.slice(2, 5) in wordRict
  - 。。。
// ```

// ### 代码

// ```javascript
/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */

var wordBreak = function(s, wordDict) {
  let dp = new Array(s.length + 1).fill(false),
      n = s.length;
  dp[0] = true; // '' 空字符串肯定是可以的
  
  for (let i = 1; i <= n; i++) {
    let curr = false;
    for (let j = 0; j < i; j++) {
      if ( dp[j] === true && wordDict.indexOf( s.slice(j, i) ) !== -1 ) {
        curr = true;
        break;
      }
    }
    dp[i] = curr;
  }
  
  return dp[s.length];
}

/*
  超时!!
  典型的 DFS，字典中的单词可重复使用
  终止条件：当前尝试的字符串长度超过 s 的长度
*/
// var wordBreak = function(s, wordDict) {
//   function dfs(curr, cIndex) {
//     if (curr.length > endIndex + 1) return ;
//     if (s.slice(0, cIndex) !== curr) return ;
    
//     if (curr === s) return ans = true;
    
//     for (let i = 0; i < wordDict.length; i++) {
//       if(wordDict[i].charAt(0) !== s.charAt(cIndex)) continue;
      
//       dfs(curr + wordDict[i], cIndex + wordDict[i].length);
//     }
//   }
  
//   let endIndex = s.length - 1,
//       ans = false;
  
//   dfs('', 0);
  
//   return ans;
// };
// ```