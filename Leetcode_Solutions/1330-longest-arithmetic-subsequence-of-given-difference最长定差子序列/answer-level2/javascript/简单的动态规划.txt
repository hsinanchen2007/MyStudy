- 例如  arr = [1,2,3,4], difference = 1 
- 从后向前遍历
- map.get(4) 就表示以4位结尾的最大长度
- 然后遍历到3 即 map.get(3) = map.get(3 + difference) + 1
```
var longestSubsequence = function(arr, difference) {
  let max = 0;
  let map = new Map();
  for (let i = arr.length - 1; i >= 0; --i) {
    let cur = ~~map.get(arr[i] + difference) + 1;
    map.set(arr[i], cur);
    max = Math.max(cur, max);
  } 
  return max;   
};
```
