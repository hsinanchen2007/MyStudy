```js
var isStraight = function(nums) {
  let res = nums.filter(cur => cur !== 0);
  let res2 = [...new Set(res)];
  if (res.length !== res2.length) return false;
  let min = Math.min(...res);
  let max = Math.max(...res);
  if (max - min <= 4 && max - min - res.length + 1 <= nums.length - res.length)
    return true;
  return false;
};
```