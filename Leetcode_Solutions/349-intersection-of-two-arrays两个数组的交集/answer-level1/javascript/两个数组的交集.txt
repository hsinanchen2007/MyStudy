借助map对象

```js
var intersection = function(nums1, nums2) {
    var result = [];
    var map = new Map();
    for (let i = 0; i < nums1.length; i++) {
        if (nums2.indexOf(nums1[i]) !== -1) {
            map.set(nums1[i], true)
        }
    }
    map.forEach( (item, index) => {
        result.push(index)
    })
    return result;
};
```

