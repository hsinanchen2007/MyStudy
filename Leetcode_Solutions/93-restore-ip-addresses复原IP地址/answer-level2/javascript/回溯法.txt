> 思路: ip 分为4段，最长位数为3位，且小于等于 255，如果每位长度大于1，则不会以0开头

```javascript
/**
 * @param {string} s
 * @return {string[]}
 */
var restoreIpAddresses = function(s) {
  let result = [];
  handler(s, result, [], 0, 0)
  return result;
};

function handler(s, result, tmp, idx, curr) {
  if (curr === 4) {
    if (idx === s.length) result.push(tmp.join("."))
    return
  }

  let n = ""
  for (let i = 0; idx + i < s.length && i < 3; i++) {
    let t = [...tmp];
    n += s[idx + i]
    if (Number(n) > 255) break;
    t.push(n)
    handler(s, result, t, idx + i + 1, curr + 1)
    if (n === "0") break;
  }
}
```