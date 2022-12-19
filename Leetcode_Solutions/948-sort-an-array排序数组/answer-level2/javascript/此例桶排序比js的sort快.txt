### 解题思路
![image.png](https://pic.leetcode-cn.com/a6c7cd2526c213e0e46ae383b909a847d2b0226c39c10411da3e9c07ef1e2608-image.png)

用了js的sort，桶排序和快速排序，桶排序略快4ms，三个基本差不多。

### 代码

```javascript
//  用JS库函数, 140 ms, 41.8 MB 
var sortArray_lib = function (nums) {
    return nums.sort((a, b) => a - b);
};

// 桶排序, 136 ms, 41.3 MB
const sortArray_bucket = nums => {
    let arr = new Int8Array(100000);
    nums.forEach(val => {
        arr[val + 50000]++;
    });
    nums = [];
    arr.forEach((val, idx) => {
        if (val != 0) {
            for (let i = 1; i <= val; i++) {
                nums.push(idx - 50000);
            }
        }
    });
    return nums;
}

// 快速排序, 156 ms, 54.6 MB
const sortArray_quick = nums => {
    if (nums.length <= 1) return nums;
    let pivot = nums.pop(),
        l = [],
        r = [];

    nums.forEach(val => {
        if (val < pivot) {
            l.push(val);
        } else {
            r.push(val);
        }
    });
    return sortArray_quick(l).concat(pivot, sortArray_quick(r));
}
```