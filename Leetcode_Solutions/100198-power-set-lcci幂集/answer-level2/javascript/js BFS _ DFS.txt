![image.png](https://pic.leetcode-cn.com/e88afd49116f83041f926584aca94e359724f10c8dc226866b84c06c177b4916-image.png)

### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */

/*
  BFS
*/
var subsets = function(nums) {
  let ans = [[]], temp = null;
  
  for(let i = 0, len = nums.length; i < len; i++) {
    let c = nums[i];
    temp = JSON.parse( JSON.stringify( ans ) );
    for (let j = 0; j < ans.length; j++) {
      let curr = ans[j];
      curr.push( c );
      temp.push( JSON.parse( JSON.stringify( curr ) ) );
    }
    ans = JSON.parse( JSON.stringify( temp ) )
    temp = null;
  }
  
  return ans;
}

/*
  DFS 72ms
*/
// var subsets = function(nums) {
//   let ans = [];
  
//   function dfs(curr, store) {
//     ans.push( [...curr] );
    
//     if (store.length === 0) return ;
    
//     for (let i = 0; i < store.length; i++) {
//       curr.push( store[i] );
//       dfs(curr, store.slice(i + 1));
//       curr.pop();
//     }
//   }
//   dfs([], nums);
  
//   return ans;
// };
```