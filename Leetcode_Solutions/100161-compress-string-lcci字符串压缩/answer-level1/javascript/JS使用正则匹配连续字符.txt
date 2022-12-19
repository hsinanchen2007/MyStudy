### 解题思路
1. 正则匹配字符串中连续字符并返回给数组
2. 将数组中每项字符及该项的长度拼接起来，返回结果

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function (S) {
  let result = '';
  let S_arr = S.match(/([a-zA-Z])\1*/g);
  if(S_arr) { // 不作这个判断，LeetCode会报S_arr为null的错误
    S_arr.forEach(function(item) {
        result += item.charAt(0) + item.length;
    })
  }
  return result.length >= S.length ? S : result;
};
```