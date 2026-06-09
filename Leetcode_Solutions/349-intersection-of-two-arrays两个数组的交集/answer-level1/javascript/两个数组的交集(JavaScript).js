### 解题思路
将数组1的不重复元素统计出来，遍历数组二，如果在数组2中存在，则是一个重复元素

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
  const arr = [];
  const tmp = {};

  var i = 0;
  var length = Math.max(nums1.length, nums2.length);

  while (i < nums1.length) {
    var j = nums1[i];
    if (j !== undefined && tmp[j] === undefined) {
      tmp[j] = 1;
    }
    i++;
  }
  console.log(tmp);

  var t = 0;
  while (t < nums2.length) {
    var k = nums2[t];

    if (k !== undefined && tmp[k] !== undefined && tmp[k] === 1) {
      arr.push(k);
      tmp[k] = 0;
    }
    t++;
  }
  console.log(tmp);

  return arr;
};
```