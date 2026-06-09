### 解题思路
> 首先写出一个根据输入的n = i 时的字符串集，输出 n = i + 1 时的字符串集的loop函数，例如假如输入的是'1211'，那么loop函数输出的即为'111221',然后根据输入的 n ，循环执行loop函数即可

### 代码

```javascript
var countAndSay = function(n) {
  function loop(strs) {
    const strs_split = strs.split("");
    if (strs_split.every(str => str === strs_split[0])) {
      return `${strs_split.length}${strs_split[0]}`;
    }
    let flat = strs_split[0];
    let n = 0;
    let res_arr = [];
    for (let i = 0, len = strs_split.length; i < len; i++) {
      if (strs_split[i] === flat) {
        ++n;
        i === len - 1 && res_arr.push(String(n), strs_split[i]);
      } else {
        res_arr.push(String(n), strs_split[i - 1]);
        n = 1;
        flat = strs_split[i];
        i === len - 1 && res_arr.push(String(n), strs_split[i]);
      }
    }
    return res_arr.join("");
  }
  let result = "1";
  while (n > 1) {
    result = loop(result);
    n--;
  }
  return result;
};
```