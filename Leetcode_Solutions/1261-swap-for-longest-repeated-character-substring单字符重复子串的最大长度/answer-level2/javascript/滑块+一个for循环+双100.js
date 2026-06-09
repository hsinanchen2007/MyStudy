```
var maxRepOpt1 = function (text) {
  // 每个字母可能返回的最大结果 因为每个结果不能超过字母出现的次数 统计的是滑块的长度
  // 例如 aaabaaa 会统计a的最大长度为7 如果得到a的出现次数只有6次 最后会返回结果6
  let res = new Array(26).fill(1);
  // 统计每个字母出现的次数
  let cache = new Array(26).fill(0);
  // 当前的滑块
  let arr = [];
  for (let char of text) {
    let code = char.codePointAt() - 97;
    ++cache[code]
    let len = arr.length - 1;
    if (len < 1) {
      arr.push(code);
    } else if (arr[len] === arr[len - 1]) {
      // 滑块最后两个字母相同
      // 有 aaaa  或者  baaaa 两种
      if (code === arr[len]) {
        res[code] = Math.max(res[code], len + 2);
      } else {
        arr.splice(0, arr.findIndex(el => el !== arr[len]) + 1)
      }
      arr.push(code);
    } else if (arr[len] === code) {
      // 滑块最后两个字母不相同 并且当前字母与滑块最后的一个字母相同
      // 有 ab + b 或者 aaaab + b 或者 bab + b 三种
      if (arr[len - 2] !== arr[len]) {
        res[code] = Math.max(res[code], 3);
        arr = [arr[len - 1], arr[len], code];
      } else {
        res[code] = Math.max(res[code], len + 2);
        arr.push(code);
      }
    } else if (arr[len - 1] === code) {
      // 滑块最后两个字母不相同 并且当前字母与滑块的倒数第二个字母相同
      // 有 ab + a  或者 aaaab + a 或者 bab + a 三种
      if (len > 1 && arr[len - 2] !== arr[len - 1]) {
        if (arr[len] === code) res[code] = Math.max(res[code], 3);
        arr = [code, arr[len], code];
      } else {
        res[code] = Math.max(res[code], len + 2);
        arr.push(code);
      }
    } else {
      // 滑块最后两个字母不相同 并且当前字母与滑块最后二个字母也不相同
      arr = [arr[len], code];
    }
  }
  let result = 0;
  cache.forEach((el, i) => {
    result = Math.max(result, Math.min(el, res[i]))
  })
  return result;
};
```
