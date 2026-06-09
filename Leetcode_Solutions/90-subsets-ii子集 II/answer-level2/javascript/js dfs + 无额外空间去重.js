![image.png](https://pic.leetcode-cn.com/30ed627a04d7a08b1d7f558a68ecd304c9acc33f31815822b09475a1a18b6700-image.png)

### 解题思路
```js
DFS
怎么感觉好多题都是一样的，字符串数组来回切换
```

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */

var subsetsWithDup = function(nums) {
  let ans = [];
  
  function dfs(curr, store) {
    ans.push( [...curr] );
    
    if (store.length === 0) return ;
    
    for (let i = 0; i < store.length; i++) {
      if (i > 0 && store[i] === store[i - 1]) continue;
      curr.push( store[i] );
      dfs(curr, store.slice(i + 1));
      curr.pop();
    }
  }
  
  nums.sort((a, b) => a - b);
  dfs([], nums);
  
  return ans;
};
```