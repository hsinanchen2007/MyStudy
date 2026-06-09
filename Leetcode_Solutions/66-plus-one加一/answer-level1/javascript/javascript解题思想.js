先转化 `digits` 顺序，最后 `plus one` 之后转化回来。

```
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function (digits) {
  const values = digits.reverse();
  let i = 0;
  values[i] += 1;
  while (true) {
    if (values[i] >= 10) {
      values[i] = 0;
      if (values[i + 1] === undefined) {
        values[i + 1] = 1;
        break;
      } else {
        values[i + 1] += 1
      }
      i++
    } else {
      break;
    }
  }
  return values.reverse()
};
```