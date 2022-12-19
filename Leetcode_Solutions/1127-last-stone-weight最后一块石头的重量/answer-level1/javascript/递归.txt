### 解题思路
递归

### 代码

```javascript
var lastStoneWeight = function(stones) {
  if (!stones.length) {
    return 0;
  }
  if (stones.length === 1) {
    return stones[0];
  }

  const stones_sort = stones.sort((a, b) => a - b)
  const select_stones = stones_sort.splice(-2);
  let smash_stones = [];
  if (select_stones[0] !== select_stones[1]) {
    smash_stones = smash_stones.concat(select_stones[1] - select_stones[0]);
  }
  return lastStoneWeight(stones_sort.concat(smash_stones));
};
```