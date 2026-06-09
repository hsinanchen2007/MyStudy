### 解题思路
![image.png](https://pic.leetcode-cn.com/94d666c0d0b6231033544179268533f41fab4cb83b384abe049750a41cd63ac6-image.png)

- 通过 Map 进行计数
- 通过forEach两层遍历
- 通过Array.from(res).sort() 排序

### 代码

```javascript
/**
 * @param {number[][]} mat
 * @param {number} k
 * @return {number[]}
 */
var kWeakestRows = function(mat, k) {
  let res = new Map();
  mat.forEach((item, index) => {
    let j = 0;
    item.forEach(i => {
      if (i == 1) {
        j++;
      }
    });
    res.set(index, j);
  });

  let arr = Array.from(res).sort((a, b) => {
    if (a[1] - b[1] == 0) {
      return a[0] - b[0];
    }
    return a[1] - b[1];
  });

  let arrX = arr.slice(0, k).map(item => item[0]);
  return arrX;

};
```