![image.png](https://pic.leetcode-cn.com/2e80c4752652292c8fac4dc12386f7b75b0068ad28460a6566c24691a5776007-image.png)

### 解题思路
```javascript
滑动窗口
```

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */

var lengthOfLongestSubstring = function(s) {
  let ans = 0, window = {}, left = 0, right = 0, len = s.length;
  
  while (right < len) {
    while (window[ s[right] ] === undefined && right < len) {
      window[ s[right] ] = 1;
      right++;
    }
    ans = Math.max(ans, right - left);
    while (window[ s[right] ] === 1 && left < right) {
      window[ s[left] ] = undefined;
      left++;
    }
  }
  
  return ans;
}

/*
  170ms
  思路：
  用 map(对象也可以) + 队列
  - 用 map 记录字符串出现次数，如果不重复一直向栈中压入元素
  - 如果遇到重复的值，那么统计此时的队列长度，对比之前找到的最长子串长度，更新值
  - 从队列头部消除元素，直到消除掉与当前元素相同的元素，将当前元素放入队列
  
  - 重复上述步骤
*/
// var lengthOfLongestSubstring = function(s) {
//   let map = {},
//       queue = [],
//       ans = 0;
  
//   for (let i = 0, len = s.length; i < len; i++) {
//     let c = s.charAt(i);
//     if (map[c]) {
//       ans = Math.max(ans, queue.length);
//       while (queue.length > 0 && map[c] !== undefined) {
//         map[queue.shift()] = undefined;
//       }
//     }
//     queue.push( c );
//     map[c] = 1;
//   }
  
//   ans = Math.max( ans, queue.length );
  
//   return ans;
// };
```