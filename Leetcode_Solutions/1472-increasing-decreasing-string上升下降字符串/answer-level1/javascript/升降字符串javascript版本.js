### 解题思路
建一个存所有字符个数的Map;
每从小到大输出一次 Map中字母个数减1，从大到小只需要把Map获得的key倒序排列即可；
当Map中所有字母的个数都为0；跳出while循环；
输出结果

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var sortString = function(str) {
  let letterMap = {};
  let result = '';
  let flag = false;
  str.split('').forEach(s => {
    letterMap[s] ? letterMap[s]++ : letterMap[s] = 1;
  });
  while(!flag) {
    let keys = Object.keys(letterMap);
    keys = keys.sort((a,b) => a < b ? -1 : 1);
    flag = true;
    keys.forEach(key=> {
      if(letterMap[key] > 0) {
        result = result.concat(key);
        flag = false;
      }
      letterMap[key]--;
    });
    let sortKeys = Object.keys(letterMap);
    sortKeys = sortKeys.sort((a,b) => a > b ? -1 : 1);
    sortKeys.forEach(key=> {
      if(letterMap[key] > 0) {
        result = result.concat(key);
        flag = false;
      }
      letterMap[key]--;
    });
  }
  return result;
};
```