### 解题思路

该题目即为[莱温斯坦距离](https://zh.wikipedia.org/wiki/%E8%90%8A%E6%96%87%E6%96%AF%E5%9D%A6%E8%B7%9D%E9%9B%A2), 详解请参考[GitHub](https://github.com/JiangLiruii/algorithm/blob/master/%E7%AC%AC41%E8%AE%B2-%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92(%E5%AE%9E%E6%88%98).md)

>考虑以下几种情况:(i,j 分别表示两个字符串的位置)

> - i 和 j 对应的字符相同, 那么继续比较i+1和j+1
> - i 和 j 对应的字符不相同, 又有多重处理方式:
> - 删除 i, 比较 i+1和 j
> - 删除 j, 比较 i 和 j+1
> - i 替换成 j, 继续比较 i+1, j+1
> - i 前加一个跟 j 一样的字符, 继续比较 i 和 j+1
> - j 前加一个跟 i 一样的字符, 继续比较 i+1和 j
> - 实际上2,4和1,5在代码上是一样的

直接使用回溯算法会超时, 所以需要优化, 对已经计算过的情况进行保留

状态转移方程:
a[i] === b[j]
`min_dist(i+1,j+1) = Math.min(min_dist(i, j+1)+1, min_dist(i+1,j)+1, min_dist(i,j))`可由下面的不等于时i+1, j+1为最小值而推出 `min_dist(i+1, j+1) = min_dist(i,j)`

如果 a[i] !== b[j]
`min_dist(i+1,j+1) = Math.min(min_dist(i, j)+1, min_dist(i,j+1)+1, min_dist(i+1,j)+1) = Math.min(min_dist(i, j), min_dist(i,j+1), min_dist(i+1,j))+1`

### 代码

```javascript
/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
    // 行为 str_1, 列为 str_2
  const n = word1.length;
  const m = word2.length;
  // 为0的情况单独处理
  if(n === 0 || m === 0) return m||n
  const result = new Array(n)
  let min_count;
  // 生成第一列的数据
  for (let i = 0; i <= n; i++) {
    result[i] = []
    result[i][0] = i
  }
  // 生成第一行的数据
  for (let i = 0; i <= m; i++) {
    result[0][i] = i;
  }

  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= m; j++) {
      if (word1[i-1] === word2[j-1]) {
          // 动态规划
        result[i][j] = result[i-1][j-1]
      } else {
        result[i][j] = Math.min(result[i-1][j], result[i][j-1], result[i-1][j-1]) + 1
      }
    }
  }
  return result[n][m]
};
```