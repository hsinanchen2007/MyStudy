### 解题思路
也是通过排序+二分法获取最大子串长度解决的。
1. 将height升序排列，如果遇到同值，将对应序列的weight进行降序排列
2. 使用二分法获取weight的最大子串的长度，就是最终结果(有关二分法获取最大子串长度可以参考[第300题的题解](https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/))

![2451583120162_.pic.jpg](https://pic.leetcode-cn.com/13dccdbcef8613ee98154d12d404ae0caa16e95182a11eb6d7ffa64647405d8b-2451583120162_.pic.jpg)

### 代码

```javascript
/**
 * @param {number[]} height
 * @param {number[]} weight
 * @return {number}
 */
var bestSeqAtIndex = function(height, weight) {
  const data = [];
  const dp = [];
  for(let i = 0;i < height.length;i++) {
    const item  = {
      height: height[i],
      weight: weight[i]
    };
    data.push(item);
  }
  data.sort(function(a, b) {
    if(a.height === b.height) {
      return b.weight - a.weight;
    }
    return a.height - b.height;
  });
  // 利用二分法获取weight的最长子串的值就是结果
  let res = 0;
  for(let index in data) {
    index = Number(index);
    let w = data[index].weight;
    let i = 0;
    let j = res;
    while(i < j) {
      const m = parseInt((i + j) / 2);
      if(dp[m] < w) {
        i = m + 1;
      } else {
        j = m;
      }
    }
    dp[i] = w;
    if(j === res) res++;
  }
  return res;
};
```