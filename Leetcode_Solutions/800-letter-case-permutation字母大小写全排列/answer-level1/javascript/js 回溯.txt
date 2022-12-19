![image.png](https://pic.leetcode-cn.com/441856ea0526a0e3cf66c13b0881ee529c6dc6046e32f539df2921f75c020480-image.png)

### 解题思路
思路：从空字符串开始回溯，一个字符串一个字符串加，加到字母的时候，分别拼接 小写 和 大写 进行回溯，否则，普通回溯即可

### 代码

```javascript
/**
 * @param {string} S
 * @return {string[]}
 */
var letterCasePermutation = function(S) {
  let ans = [],
      letters = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
  
  function backtrack(str, i) {
    if (i >= S.length) {
      ans.push( str );
      return ;
    }
    
    let curr = S[i];
    if (letters.indexOf( curr ) > -1) {
      let low = str + curr.toLowerCase(),
          high = str + curr.toUpperCase();
      backtrack( low, i + 1 );
      backtrack( high, i + 1 );
    } else {
      backtrack( str + curr, i + 1 );
    }
  }
  backtrack( '', 0 );
  
  return ans;
};
```