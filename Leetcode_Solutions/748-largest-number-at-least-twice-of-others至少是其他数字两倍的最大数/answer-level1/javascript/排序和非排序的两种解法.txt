### 方法一
先排序后比较最大和第二大的即可

### 代码

```javascript
var dominantIndex = function(nums) {
    let original = [...nums], n = nums.length;
    nums.sort((a, b) => a - b);

    let max = nums[n - 1], sec = nums[n - 2];

    if (max < 2 * sec) return -1;

    return original.indexOf(max);
};
```

### 方法二
一直维护两个数，一个最大，一个第二大
```
var dominantIndex = function(nums) {
    let f = 0, s = 0;

    for (let n of nums) {
        if (n > f) {
            s = f;
            f = n;
        } else if (n > s) {
            s = n;
        }
    }

    if (2 * s > f) return -1;

    return nums.indexOf(f);
}
```
