 因为看到一堆用了排序,似乎根本不知道什么叫时间复杂度.所以贴出来.

``` js
let findMedianSortedArrays = function(nums1, nums2) {
  let len1 = nums1.length,len2 = nums2.length;
  let mid = len1 + len2 >> 1; // 中位数位置, 取mid mid+1两个
  let i = 0,j = 0,cur;
  let n1,n2;
  while(i<len1 || j<len2){
    if(j === len2 || nums1[i] < nums2[j]){
      cur = nums1[i];
      i ++;
    }else{
      cur = nums2[j];
      j ++;
    }
    if(i + j === mid){
      n1 = cur
    }
    if(i + j === mid + 1) {
      n2 = cur;
      break;
    }
  }
  return (len1 + len2) % 2 === 0 ? (n1 + n2)/2 : n2;
};
```
