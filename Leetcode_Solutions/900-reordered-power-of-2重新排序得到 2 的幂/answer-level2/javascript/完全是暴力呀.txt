把已知范围内所有数，排序搜集起来，然后对输入整数排序对比！

```
/**
 * @param {number} N
 * @return {boolean}
 */
var reorderedPowerOf2 = function(N) {
  let all = {
    "012356789": true,
    "234455668": true,
    "112234778": true,
    "01466788": true,
    "23334455": true,
    "11266777": true,
    "0368888": true,
    "0134449": true,
    "0122579": true,
    "0145678": true,
    "224588": true,
    "122446": true,
    "011237": true,
    "35566": true,
    "23678": true,
    "13468": true,
    "1289": true,
    "0469": true,
    "0248": true,
    "0124": true,
    "125": true,
    "256": true,
    "128": true,
    "46": true,
    "23": true,
    "16": true,
    "8": true,
    "4": true,
    "2": true,
    "1": true
  };

  if (N < 60) {
    return all[N] || false;
  } else {
    return all[
      ("" + N)
        .split("")
        .sort((a, b) => a - b)
        .join("")
    ] || false;
  }
};
```
