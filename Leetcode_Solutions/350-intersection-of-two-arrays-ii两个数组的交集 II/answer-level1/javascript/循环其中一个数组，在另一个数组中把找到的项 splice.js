循环其中一个数组，在另一个数组中把找到的项 splice （不是最优解，只是一个思路）
执行用时：72 ms
内存消耗：33.9 MB

```js
var nums1 = [3, 1, 2, 1];
var nums2 = [1];

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
  var arr = [];

  // 1.循环其中一个数组
  nums1.forEach(v => {
    var index = nums2.indexOf(v);

    if (index !== -1) {
      // 2.找到的话就切除
      // 如果不去掉，循环的数组中后续还有一项与该项相同，将会重复。如开头自定义的两个数组
      nums2.splice(index, 1);
      
      // 3.将循环数组中匹配到的当前项存入
      arr.push(v);
    }
  });

  return arr;
};
```
