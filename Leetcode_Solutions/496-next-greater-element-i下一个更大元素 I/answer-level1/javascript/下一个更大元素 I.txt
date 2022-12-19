暴力双循环

```js
var nextGreaterElement = function(nums1, nums2) {
    let arr = [];
    for (let i = 0; i < nums1.length; i++) {
        let start = nums2.indexOf(nums1[i]) + 1;
        let isFind = false;
        for (let j = start; j < nums2.length; j++) {
            if (nums2[j] > nums1[i]) {
                arr.push(nums2[j]);
                isFind = true;
                break;
            }
        }
        if (!isFind) {
            arr.push(-1);
        }
    }
    return arr;
};
```

