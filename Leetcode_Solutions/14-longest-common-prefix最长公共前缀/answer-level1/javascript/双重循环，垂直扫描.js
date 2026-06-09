# 代码
```javascript []
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
  strs.sort((a,b) => a.length - b.length > 0);
  let str = strs[0] || '';
  
  for(let i = 0; i < strs.length; i++) {
    for (let j = 0; j < str.length; j ++) {
      if (strs[i][j] !== str[j]) {
        if (j === 0) return ''
        str = str.substr(0, j);
      }
    }
  }
  return str;
};
```

# 思路
1. 先按各字符串长度排序，将长度最小的字符串赋值给最大公共前缀str，作为初始值
2. 遍历字符串数组，使用str与strs[i]两两比对取得新的最大公共前缀赋值给str
3. str长度等于0时直接返回''

# 分析
同样的代码提交两次竟然会用时不同。。什么鬼。
![ET(U_GM2@\]2LX19MV0F8HUJ.png](https://pic.leetcode-cn.com/d100b77188456752b0244a12d50b135f1b76befe5a8674f491a2b25793d15e9a-ET\(U_GM2@%5D2LX19MV0F8HUJ.png)

- 所以时间复杂度应该为: O((minLen + 2) * n) **?**   (假设此处排序方法sort的复杂度为O(2n)
