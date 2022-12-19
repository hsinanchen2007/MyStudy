### 明确：题目中的输入nums1的实际长度为m+n，后面的n个元素值为0
### 法一：合并后排序
- splice和sort改变原数组
```
var merge = function (nums1, m, nums2, n) {
  nums1.splice(m, n, ...nums2)
  nums1.sort((a, b) => a - b)
  return nums1
}
```
### 法二：双指针
- 从后往前找
- 利用数组的有序特性
- 下面的代码借鉴大佬思想，不过是容易理解的写法
```
var merge = function (nums1, m, nums2, n) {
  var i=m-1
  var j=n-1
  var index=m+n-1
  while(i>=0&&j>=0){
    if(nums1[i]>nums2[j]){
      nums1[index]=nums1[i]
      i--
    }else{
      nums1[index]=nums2[j]
      j--
    }
    index--
  }
  if(j>=0){
    nums1.splice(0,j+1,...nums2.slice(0,j+1))
  }
};
```
