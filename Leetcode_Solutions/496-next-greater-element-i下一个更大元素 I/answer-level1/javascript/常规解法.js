## 解题思路
- 遍历nums1
- 在nums2中获取当前nums1元素的位置，然后从下一位置开始遍历对比，有则返回，无责返回-1.

```javascript
var nextGreaterElement = function(nums1, nums2) {
  let result = [];

  nums1.forEach((item) => {
    let idx = nums2.indexOf(item);
    let nextVal = checkNext(idx, nums2);
    result.push(nextVal);
  });

  return result;

  function checkNext(idx, nums2) {
    let current = nums2[idx];

    for(let i = idx + 1; i < nums2.length; i++) {
      if (nums2[i] > current) {
        return nums2[i];
      }
    }

    return -1;
  }
};
```