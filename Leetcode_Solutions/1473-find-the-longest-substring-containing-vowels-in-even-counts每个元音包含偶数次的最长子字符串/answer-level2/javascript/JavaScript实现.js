### 解题思路
参考了[mnizy](https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/solution/jian-dan-de-si-lu-by-mnizy/)的C++的题解。
充分理解之后，在此基础上再解释一下吧，这个思路是化繁为简，把5个元音字母出现的奇偶次数当做状态来存储，总共会出现32种可能的结果(2的5次方)，这个解法最巧妙的是把状态用二进制来存储了，直接用异或运算，速度非常快。

### 代码

```javascript
var findTheLongestSubstring = function(s) {
  var state = new Array(32)
  var cur = 0;
  var ans = 0;
    state[0] = -1
  for(let i = 0; i < s.length; i ++) {
    switch (s[i]) {
      case 'a':
        cur^=1;
        break;
      case 'e':
        cur^=2;
        break;
      case 'i':
        cur^=4;
        break;
      case 'o':
        cur^=8;
        break;
      case 'u':
        cur^=16;
        break;
      default:
        break;
    }
    if(state[cur] === undefined) {
      state[cur] = i
    } else {
      ans = Math.max(ans, i - state[cur])
    }
  }
  return ans
};
```