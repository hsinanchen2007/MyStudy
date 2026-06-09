照着官方的写法写了一版，思路:
- 找到第一个左边比右边小的数
- 让该数之后升序排序

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function(nums) {
  if (nums.length <= 1) return;
  let len1 = nums.length -2;
  while(len1 >= 0 && nums[len1] >= nums[len1+1]) {
    len1--;
  }
  if(len1 >= 0) {
    let len2 = nums.length - 1;
    while(len2 >=0 && nums[len2] <= nums[len1]) {
        len2--;
    }
    swap(nums,len1,len2);
  }
  reserve(nums,len1+1); // 从交换的下一个位置开始时排序
};
const reserve = function(nums,len) {
    let len1 = len;
    let len2 = nums.length -1;
    while(len1 < len2) {
        swap(nums,len1,len2);
        len1++;
        len2--;
    }
}
const swap = function(nums,len1, len2) {
  let temp = nums[len1];
  nums[len1] = nums[len2];
  nums[len2] = temp;
}
```
时间复杂度：O(n)，在最坏的情况下，只需要对整个数组进行两次扫描。
空间复杂度：O(1)，没有使用额外的空间，原地替换足以做到。