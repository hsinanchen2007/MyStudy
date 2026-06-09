1. 对于不是z的节点 上下 左右的方向都是确定的 且没有先后关系
2. 如果z在起点  则必须 先上后右
3. 如果z在终点  则必须 先左后下
4. 即对于所有的字母 可以采用和多种方向组合
5. 上左右下 左上右下  上右左下 左下上右 等等都是可行的
```
var alphabetBoardPath = function (target) {
  let getPath = function (from, to) {
    if (from === to) return '!'
    let codeFrom = from.codePointAt() - 97;
    let codeTo = to.codePointAt() - 97;
    let y = Math.floor(codeFrom / 5) - Math.floor(codeTo / 5)
    let x = codeFrom % 5 - codeTo % 5
    let res = '';
    if (y > 0) res += 'U'.repeat(y)
    if (x < 0) res += 'R'.repeat(-x)
    if (x > 0) res += 'L'.repeat(x)
    if (y < 0) res += 'D'.repeat(-y)
    return res + '!';
  }
  let res = '';
  for (let i = 0, from = 'a', len = target.length; i < len; ++i) {
    res += getPath(from, target[i]);
    from = target[i];
  }
  return res;
};
```
