### 解题思路
第一步删掉nums1多余的项，然后把nums2的元素追加到nums1，再进行排序。

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    nums1.splice(m,nums1.length - m)
    nums2.forEach(item => { nums1.push(item) });

    nums1.sort((val1,val2) => {
       return (val1 < val2 ? -1 : 1)
    });
};
```



记录一个踩的坑，最开始写的时候，在删掉nums1这一步上用了slice，自己编译器上运行正确，但放上来执行却发现输出还是原数组，
后来反应过来，slice返回的是新数组，把一个新数组赋给nums1，相当于指向了另一个内存地址，所以这种写法输出不同:

``` js
var merge = function(nums1, m, nums2, n) {
    nums1 = nums1.slice(0,m)            //这里指向了另外一个内存地址
    nums2.forEach(item => {
        nums1.push(item)
    });

    nums1.sort();
};
```