定义数组 tails[i] 表示 nums2 中未被添加的与 nums1[i] 相加最小的下标
由于 nums1 和 nums2 都是升序的
显然当前最小值在 nums1[0] + nums2[tails[0]], nums1[1] + nums2[tails[1]] ... nums1[n] + nums2[tails[n]] 之中
```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number} k
 * @return {number[][]}
 */
var kSmallestPairs = function(nums1, nums2, k) {
  let n = nums1.length;
  let m = nums2.length;

  k = k > n * m ? n * m : k;

  // tails[i] 表示 nums2 中与 nums1[i] 相加最小的下标
  let tails = [];

  for (let i=0; i<n; i++) {
    tails[i] = 0;
  }

  let result = [];

  while(k > 0) {
    let minIndex = 0;
    let minCount = 2147483647;
    for (let i=0; i<tails.length; i++) {
      if (tails[i] >= m) {
        continue;
      }
      if (nums1[i] + nums2[tails[i]] < minCount) {
        minIndex = i;
        minCount = nums1[i] + nums2[tails[i]];
      }
    }
    result.push([nums1[minIndex], nums2[tails[minIndex]]]);
    tails[minIndex] ++;
    k --;
  }

  return result;
};
```
时间复杂度 O(nk), 空间复杂度 O(n), n 为 nums1 长度
