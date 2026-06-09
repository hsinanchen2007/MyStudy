![image.png](https://pic.leetcode-cn.com/4e2070c2697c6550bdf16cf53cb891e8b2792a0e7a2cd06c9babf744e98b2333-image.png)

### 解题思路
```js
这种去重方式。。。em。。得手动画流程理解一下

去重的本质是开始重复的时候就去掉这次尝试就不会重复了
假设测试用例为 'aba'
我们首先要排序，让相同字符挨在一起 => 'aab'
开始尝试各种排列，开始进来的时候是空字符串 ''，可选字符为 'aab'
  有三种方式：
    1) 拿第一个字符'a' => 'a'    剩余 'ab'
    2) 拿第二个字符'a' => 此时发现上一次相邻的尝试拿的也是 'a'，所以判断为重复，跳过这次尝试
    3) 拿第三个字符'b' => 'b'    剩余 'aa'

第二种情况就被我们去重掉了，因为我们是不断的尝试，所以只需要在每次尝试之前判断：这次尝试所拿的字符
和上一次相邻尝试所拿的字符是否相同，相同即为重复，直接跳过即可，可称为“剪枝”
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
      if (i > 0 && store[i] === store[i - 1]) continue; // 去重
      curr += store[i];
      dfs(curr, store.slice(0, i).concat( store.slice(i + 1) ));
      curr = curr.slice(0, curr.length - 1);
    }
  }
  
  // 先排序。为了去重
  S = S.split('');
  S.sort((a, b) => {
    if (a > b) return 1;
    return -1;
  });
  S = S.join('');
  dfs('', S);
  
  return ans;
};

/*
  使用额外的对象去重
*/
// var permutation = function(S) {
//   let ans = [], map = {};
  
//   function dfs(curr, store) {
//     if (store === '' && map[curr] === undefined) {
//       map[curr] = 1;
//       return ans.push( curr );
//     }
    
//     for (let i = 0, len = store.length; i < len; i++) {
//       curr += store[i];
//       dfs(curr, store.slice(0, i).concat( store.slice(i + 1) ));
//       curr = curr.slice(0, curr.length - 1);
//     }
//   }
  
//   dfs('', S);
  
//   return ans;
// };
```