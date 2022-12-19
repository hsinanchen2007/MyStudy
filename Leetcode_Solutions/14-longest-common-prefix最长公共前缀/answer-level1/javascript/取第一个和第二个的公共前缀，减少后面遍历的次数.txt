### 解题思路
取第一个和第二个的公共前缀，减少后面遍历的次数

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
  const strLen = strs.length;
  if(strLen === 1) return strs[0];
  if(strLen === 0) return "";
  let result = "";
  const first = strs[0].split('');
  const second = strs[1].split('');

  first.find((item, index) => {
    if(second[index] === item) {
      result = result + item;
      return false
    }
    return true;
  })

  result && strs.forEach(item => {
    result = checkStr(item, result);
  })

  return result;
};

var checkStr = function(item, str) {
  if(item.substring(0, str.length) !== str) {
    return checkStr(item, str.slice(0, str.length - 1))
  }
  return str;
} 
```