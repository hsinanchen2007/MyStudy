### 方法一
先将数组扁平化,然后模拟循环即可,效率较低

### 代码

```javascript
var matrixReshape = function(nums, r, c) {
    let newArr = new Array(r).fill(0).map(_ => new Array(c).fill(0)), k = 0;
    // 扁平化数组
    let flat = flatten(nums);
    if (flat.length < r * c) return nums;

    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            newArr[i][j] = flat[k++];
        }
    }
    return newArr;
};

function flatten(arr) {
    return arr.reduce((pre, cur) => Array.isArray(cur) ? [...pre, ...flatten(cur)] : [...pre, cur], []);
}
```

### 方法二
直接模拟
### 代码
```
var matrixReshape = function(nums, r, c) {
    if (nums.length * nums[0].length < r * c) return nums;

    let res = new Array(r).fill(0).map(_ => new Array(c).fill(0)), p = 0, q = 0;

    for (let i = 0; i < nums.length; i++) {
        for (let j = 0; j < nums[0].length; j++) {
            res[p][q++] = nums[i][j];
            if (q == c) {
                q = 0;
                p++;
            }
        }
    }
    return res;
}
```
