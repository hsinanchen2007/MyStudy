![image.png](https://pic.leetcode-cn.com/6236554163e9280bf3c5534234a38772c115d006e1ea042bbb30633e1f0b5a16-image.png)

### 解题思路
```js
无额外空间去重 + DFS
偷个懒，题解看这里，已经写过一遍了，哈哈：
https://leetcode-cn.com/problems/permutation-ii-lcci/solution/js-hui-su-qu-zhong-by-ignore_express/
```

### 代码

```javascript
/**
 * @param {string} s
 * @return {string[]}
 */

var permutation = function(s) {
  let ans = [];
  
  function dfs(curr, store) {
    if (store.length === 0) {
      return ans.push( curr );
    }
    
    for (let i = 0; i < store.length; i++) {
      if (i > 0 && store[i] === store[i - 1]) continue;
      curr += store[i];
      dfs(curr, store.slice(0, i).concat( store.slice(i + 1) ));
      curr = curr.slice(0, curr.length - 1);
    }
  }
  
  s = s.split('');
  s.sort((a, b) => {
    if (a > b) return 1;
    return -1;
  });
  s = s.join('');
  
  dfs('', s);
  
  return ans;
};
```