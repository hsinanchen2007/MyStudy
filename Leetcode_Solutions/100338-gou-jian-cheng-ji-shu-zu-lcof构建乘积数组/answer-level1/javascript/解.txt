### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} a
 * @return {number[]}
 */
var constructArr = function(a) {

    let ans = [],
        leftProduct = rightProduct = 1 // leftProduct RightProduct 分别为左右两侧的累乘

    for (let i = 0; i < a.length; i++) {
        ans[i] = leftProduct
        leftProduct *= a[i]
    }

    for (let i = a.length - 1; i >= 0; i--) {
        ans[i] *= rightProduct
        rightProduct *= a[i]
    }

    return ans
};
```