```javascript
var intersection = function(nums1, nums2) {
    //数组交集
    let intersect = nums1.filter(x => nums2.includes(x));
    //数组去重
    return [... new Set(intersect)];
};
```

