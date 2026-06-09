### 解题思路

大家好，我是 17

官方版本把 A 也进行了 clone，这个没有必要，其它的一样。

1. 把 A，B排序 ，但保留 B 的原始数据 oldB，方便后面按原始数据的位置输出 A 的数据
2. 从 A 和 B 最小的数开始，遇到 比 B 大 的就记录到 map,比 B小的就保留在 remain
3. 按 oldB 的顺序输出，map里有的，就输出 map里的，没有就输出　remain里的。

### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number[]} B
 * @return {number[]}
 */
var advantageCount = function (A, B) {
  A.sort((a, b) => a - b)
  let oldB=B.slice()
  B.sort((a, b) => a - b)
  let remain = [], map = new Map()
  let i = 0;
  for (let a = 0, b = 0; a < A.length; a++) {
    if (A[a] > B[b]) {
      if (map.has(B[b])) {
        map.get(B[b]).push(A[a])
      }
      else {
        map.set(B[b], [A[a]])
      }
      b++
    }
    else {
      remain.push(A[a])
    }
  }
  let result = []
  for (let n of oldB) {
    if (!map.has(n) || map.get(n).length === 0) {
      result.push(remain.pop())
    }
    else {
      result.push(map.get(n).pop())
    }
  }
  return result

};
```