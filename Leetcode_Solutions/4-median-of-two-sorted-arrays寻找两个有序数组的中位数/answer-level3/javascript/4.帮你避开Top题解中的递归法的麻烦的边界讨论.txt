排名第一的递归法中的基本思路相信大家话费一些时间就能看懂。但是对于边界讨论情况可能会耗费更多的时间。

在TOP题解中提到需要对两个条件进行判断，但是在在i，j触发到边界时，

**如果A[i−1],B[j−1],A[i],B[j] 中部分不存在，那么我们只需要检查这两个条件中的一个（或不需要检查）。**

在这里做个总结：
- 在检查上面两个条件时，只有返回值是true的时候，才需要对imin，imax进行数值改变。
- 如果判断的返回值是false，则不对imin，imax进行操作。
- 如果不检查上面两个条件，也不需要对imin，imax进行操作。

我发现，在判断为false和不进行检查时，我们进行的操作是相同的。

我的思路是，在i，j触发到边界时，仍然进行判断，但是判断返回值设定为false。
我是通过写一个方法getEle来做到的。同时我重写了Math.max和Math.min方法来消除getEle带来的影响。

这样大家就不用劳心劳力的判断是否触发边界情况了。

```
var findMedianSortedArrays = function (nums1, nums2) {
    if (nums1.length > nums2.length) {
        [nums1, nums2] = [nums2, nums1];
    }
    let m = nums1.length,
        n = nums2.length;
    let i, j; //分割数组时，上面有个i个元素，下面有j个元素
    let _imin = 0,
        _imax = nums1.length;
    while (true) {
        i = parseInt((_imin + _imax) / 2);
        j = parseInt((m + n + 1) / 2) - i;
        if (getEle(nums1, i - 1) > getEle(nums2, j)) {//这里进行判断时，如果任意一个值是undefined会返回false
            _imax = i - 1;
        } else if (getEle(nums2, j - 1) > nums1[i]) {
            _imin = i + 1;
        } else {
            return ((m + n) % 2 === 0) ? (getMax(getEle(nums1, i - 1), getEle(nums2, j - 1)) + getMin(getEle(nums1, i), getEle(nums2, j))) / 2 : getMax(
                getEle(nums1, i - 1), getEle(nums2, j - 1));
        }
    }
    //对于超出边界的index，直接返回undefined
    function getEle(num, index) {
        if (num.length === 0) {
            return undefined;
        } else if (index < 0 || index >= num.length) {
            return undefined;
        }
        return num[index];
    }
    //因为在调用getEle方法时，有时会返回undefined，这会影响Math.max Math.min方法的运用，所以这里重写了一个最大最小是判断的方法
    function getMax(a, b) {
        return a === undefined ? (b === undefined ? 0 : b) : (b === undefined ? a : Math.max(a, b));
    }
    function getMin(a, b) {
        return a === undefined ? (b === undefined ? 0 : b) : (b === undefined ? a : Math.min(a, b));
    }
};
```


