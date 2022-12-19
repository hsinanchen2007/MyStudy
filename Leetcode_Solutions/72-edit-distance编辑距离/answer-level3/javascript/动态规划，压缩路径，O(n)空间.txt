在官方题解基础上进行简化

由于这里唯一需要保存的是左上角的数据，因此可以将这个数进行保存，每次进行更新即可。因此可以压缩路径简化为一维数组。

```javascript
var minDistance = function(word1, word2) {
  const dp = Array.from({ length: word2.length + 1 }, (item, index) => index);
  // 保存的是左上角的值
  let before;
  for (let i = 1; i <= word1.length; i++) {
    before = dp[ 0 ];
    dp[ 0 ] = i;
    for (let j = 1; j < dp.length; j++) {
      // 先将左上角值缓存，后续在进行更新
      const temp = dp[ j ];
      const flag = word1[i - 1] === word2[j - 1] ? 1 : 0;
      dp[j] = 1 + Math.min(dp[j - 1], dp[j], before - flag);
      before = temp;
    }
  }
  return dp[ dp.length - 1 ]
};
```
