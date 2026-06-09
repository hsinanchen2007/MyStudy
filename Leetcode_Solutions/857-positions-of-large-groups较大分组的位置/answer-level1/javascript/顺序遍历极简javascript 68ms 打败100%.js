### 解题思路
边界判断上没有特殊处理，原本的 `i < S.length` 写成 `i <= S.length` 即可
这样统一，看起来更理简洁

### 代码

```javascript
/**
 * @param {string} S
 * @return {number[][]}
 */
var largeGroupPositions = function (S) {

  let start = 0, end = 0
  let result = []
  for (let i = 1; i <= S.length; i++) {
    if (S[i] === S[i - 1]) {
      end++
    }
    else {
      if (end - start >= 2) {
        result.push([start, end])
      }
      start = end = i
    }
  }
  
  return result
};

```