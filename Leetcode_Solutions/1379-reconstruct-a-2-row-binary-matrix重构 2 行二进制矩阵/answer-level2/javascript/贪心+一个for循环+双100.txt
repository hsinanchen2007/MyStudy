- 初始化一个二维数组res 默认填充0
- 容易知道只有当数组colsum的和等于upper + lower是有结果的
- 维护upper的值 表示res[0]中还应该填充1的个数
- 维护lower的值 表示res[1]中还应该填充1的个数
- 当colsum[i] === 2 时 res[0][i] = 1并且 res[1][i] = 1  --upper --lower
- 当colsum[i] === 0 时 res[0][i] = 0并且 res[1][i] = 0
- 当colsum[i] === 1 时 需要用到贪心策略
- 假设colsum[i]后面还有k个2  可以知道当前的 upper >= k 并且 lower >= k
- 并且因为当前的当colsum[i] === 1 所以upper和lower中较大的拿一个肯定大于k
- 即当选择upper和lower中较大的一个去填充1时 肯定不会出错 
```
var reconstructMatrix = function(upper, lower, colsum) {
  const res = Array.from({length: 2}, () => new Array(colsum.length).fill(0))
  for (let i = 0, len = colsum.length; i < len; ++i) {
    const num = colsum[i];
    if (num === 2) {
      ++res[0][i]
      ++res[1][i]
      --lower;
      --upper;
    } else if (num === 1) {
      if (upper >= lower && lower >= 0) {
        ++res[0][i]
        --upper
      } else if (lower >= upper && upper >= 0){
        ++res[1][i]
        --lower
      } else {
        return [];
      }
    }
  }
  return lower === 0 && upper === 0 ? res : [];
};
```
