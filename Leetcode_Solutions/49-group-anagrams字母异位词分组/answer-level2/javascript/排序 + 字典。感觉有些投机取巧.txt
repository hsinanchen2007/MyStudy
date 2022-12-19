```javascript
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
  let tmp = {};
  for (let val of strs) {
    let t = val.split("").sort().join("");
    if (tmp[t]) tmp[t].push(val);
    else tmp[t] = [val];
  }
  let result = [];
  for (let key in tmp)
    result.push(tmp[key]);
    
  return result;
};
```