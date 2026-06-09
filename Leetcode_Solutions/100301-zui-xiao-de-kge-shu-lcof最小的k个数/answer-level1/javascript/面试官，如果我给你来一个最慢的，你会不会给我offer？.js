### 解题思路
“面试官，这是我的优化，能给offer了吗？。。。。欸欸欸，不给就不给，不给也行，就当交个朋友，你别动手。。诶诶，别动手。我自己走。。。。”

![image.png](https://pic.leetcode-cn.com/142f9cf5073490e78b29bed46f02d3aca61318061b68329e701cb32987dff645-image.png)


### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function (arr, k) {
    // 1. shameful but feasible way    
    if (false) {
        let ret = [];
        arr.sort(function (a, b) { return a - b; });
        for (let i = 0; i < k; i++) {
            ret.push(arr[i]);
        }
        return ret;
    }

    // 2.
    let kArr = [];

    const intoK = (val, idx, arr) => {
        if (kArr.length === k && val <= kArr[0]) {
            kArr.shift();
            kArr.push(val);
            kArr.sort(function (a, b) { return b - a; });
        } else if (kArr.length < k) {
            kArr.push(val)
            if (kArr.length === k) kArr.sort(function (a, b) { return b - a; });
        }
    }

    arr.forEach(intoK);
    return kArr;
};
```