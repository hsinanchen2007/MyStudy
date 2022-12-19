解一：
> 数组拼接后`sort`排序。缺点是没有利用`nums1`和`nums2`本身是有序数组的优势。

```js
var merge = function(nums1, m, nums2, n) {
    for (var i = 0;i<nums2.length;i++) nums1[m+i] = nums2[i];
    nums1.sort(function (a,b) {
        return a-b
    })
};
```

解二：
> 插入排序，由于`nums1`和`num2`均为有序数组，所以`j`不需要每次循环都复位。

```js
var merge = function (nums1, m, nums2, n) {
    var j = 0;//nums1的第j位
    for (var i = 0; i < nums2.length; i++) {//nums2的第i位
        while (!(nums2[i] < nums1[j] || j >= m + i)) j++;
        for (var k = nums1.length - 1; k > j; k--) nums1[k] = nums1[k - 1];
        nums1[j] = nums2[i];
    }
};
```

⚠️坑：初始代码中有一句话："@return {void} Do not return anything, modify nums1 in-place instead."，注意其中的`in-place`，OJ不看`return`，只看`nums1`，这说明要在`num1`上做修改，并且类似`concat`和`slice`之类的方法都无效。