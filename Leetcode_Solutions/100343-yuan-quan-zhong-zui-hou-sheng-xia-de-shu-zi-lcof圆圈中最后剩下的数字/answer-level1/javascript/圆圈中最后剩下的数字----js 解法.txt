### 解题思路
思路：用数组存储，依次删除即可
 1. 定义start,作为记录起始位置
 2. 要删除的元素的索引是 从start 开始数第m个数
 3. start 是由上一个被删除的元素决定的，如果后面还有数，start = 上一次被删除的元素索引， 否则 start = 0;
### 代码

```javascript
/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */

var lastRemaining = function(n, m) {
  const arr = Array(n)
    .fill(0)
    .map((v, k) => k);
  let start = 0;

  while (n > 1) {
    const index = (start + m - 1) % n;

    n--;

    start = index + 1 > n ? 0 : index;

    arr.splice(index, 1);
  }

  return arr[0];
};

```