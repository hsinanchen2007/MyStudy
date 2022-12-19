### 解题思路

回溯法（back tracking）（探索与回溯法）是一种选优搜索法，又称为试探法，按选优条件向前搜索，以达到目标。但当探索到某一步时，发现原先选择并不优或达不到目标，就退回一步重新选择，这种走不通就退回再走的技术为回溯法，而满足回溯条件的某个状态的点称为“回溯点”。

遍历全部可能，对每种情况进行分析即可

### 代码

```javascript
/**
 * @param {number} k
 * @param {number} n
 * @return {number[][]}
 */
var combinationSum3 = function (k, n) {
  var result = [];
  var temp = [];
  var sum = 0;
  temp.push(1);
  sum += 1;
  while (temp.length) {
    if (sum === n) {
      temp.length === k && result.push(temp.slice(0));
      sum -= temp.pop();
      temp[temp.length - 1] += 1;
      sum++;
    }
    if (sum < n) {
      var last = temp[temp.length - 1];
      if (temp.length < k) {
        if (last < 9) {
          temp.push(last + 1);
          sum += last + 1;
        } else {
          sum -= temp.pop();
          temp[temp.length - 1] += 1;
          sum++;
        }
      } else {
        if (last < 9) {
          temp[temp.length - 1] += 1;
          sum++;
        } else {
          sum -= temp.pop();
          temp[temp.length - 1] += 1;
          sum++;
        }
      }
    }
    if (sum > n) {
      sum -= temp.pop();
      temp[temp.length - 1] += 1;
      sum++;
    }
  }
  return result;
};
```