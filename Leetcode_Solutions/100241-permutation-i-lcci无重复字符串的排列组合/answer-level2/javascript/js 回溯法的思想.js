![image.png](https://pic.leetcode-cn.com/02fec7ec50cae6ebf3f2ed14dcd997ecfe845abc5289bcacbe1716d040cfd168-image.png)

### 解题思路
```js
深度优先搜索的回溯：
思路：

从 '' 字符串开始，分别尝试拿每一个字符串去继续尝试

举例说明回溯的过程:
比如测试用例: 'qwe'

  进来的时候为空字符串，而可选的字符有三个 ( '', 'qwe' )
  我们可以尝试拿每一个字符串去继续尝试，有三种方式，遍历这三种方式我们使用for循环
  
  左边代表当前拿出来的，右边代表剩余可选的
    'q'  'we'
    'w'  'qe'
    'e'  'qw'
    
  这三种情况我们针对每一种情况继续进行尝试
    'q'  'we'
      - 'qw'  'e'
      - 'qe'  'w'
      
    'w'  'qe'
      - 'wq'  'e'
      - 'we'  'q'
      
    'e'  'qw'
      - 'eq'  'w'
      - 'ew'  'q'
  
    。。。这就是回溯的思想，
    继续下去，直到出现字符串长度为 3 的排列，把他加入到结果数组中
```

### 代码

```javascript
/**
 * @param {string} S
 * @return {string[]}
 */

var permutation = function(S) {
  let ans = [];
  
  function dfs(curr, store) {
    if (store === '') {
      return ans.push( curr );
    }
    
    for (let i = 0, len = store.length; i < len; i++) {
      curr += store[i];
      dfs( curr, store.slice(0, i).concat( store.slice(i + 1) ) );
      curr = curr.slice(0, curr.length - 1);
    }
  }
  dfs('', S);
  
  return ans;
};
```