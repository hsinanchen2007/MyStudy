1. 处理边缘情况，比如n为0或1。
2. 根据前一项的前index位与当前项的前index位比较：相同的情况下，index+1位前一项的index+1位；不相同情况下，index+1位为前一项的index+1位取反。
3. 递归处理得到结果，最后把二进制数组转为int数组。

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var grayCode = function(n) {
  /** 边界情况 */
  if (n === 0) { return [0]; }
  if (n === 1) { return [0, 1]; }
  const res = [];
  recureGrayCode(n, res);
  return res.map((item) => parseInt(item, 2));
};

function recureGrayCode(n, res = [], index = 0, tmp = "") {
  if (index === n) {
    res.push(tmp);
    return;
  }
  /** 获取最新一个结果的对应index的二进制 */
  let nexts = (res[res.length - 1] || "").slice(0, index) || "";
  let cur = (res[res.length - 1] || "")[index] || "";
  recureGrayCode(n, res, index + 1, `${tmp}${nexts!=="" ? (!(nexts ^ tmp) ? (cur !== "1" ? "1" : "0") : cur) : "0"}`);
  nexts = (res[res.length - 1] || "").slice(0, index) || "";
  cur = (res[res.length - 1] || "")[index] || "";
  recureGrayCode(n, res, index + 1, `${tmp}${nexts!=="" ? (!(nexts ^ tmp) ? (cur !== "1" ? "1" : "0") : cur) : "1"}`);
};
```