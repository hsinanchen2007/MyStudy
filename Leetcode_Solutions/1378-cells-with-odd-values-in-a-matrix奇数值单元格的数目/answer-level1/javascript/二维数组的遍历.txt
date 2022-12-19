### 解题思路
第一步: 首先初始化数组，根据给定的规模创建好元素全部是0的二维数组
第二步: 处理所有行所有列，分别赋值
第三步: 遍历结果集判断奇数个数

### 代码

```javascript
/**
 * @param {number} n
 * @param {number} m
 * @param {number[][]} indices
 * @return {number}
 */
var oddCells = function (n, m, indices) {
    // var arr = Array.apply(null,Array(n)).map(() =>  new Array(m));
    // var arr = new Array(n).fill(new Array(m).fill(0));
    //初始化数组
    var arr = new Array(n);
    for(var len = 0;len< n; len++){
        arr[len] = new Array(m).fill(0)
    }
    //开始赋值
    var res = 0;
    for (var i = 0; i < indices.length; i++) {
        //处理所有行
        arr[indices[i][0]].forEach(function (currentValue, index) {
            arr[indices[i][0]][index] += 1;
        });
        //处理所有列
        arr.forEach(function (currentValue, index) {
            arr[index][indices[i][1]] += 1;
        })
    }
    //判断奇数偶数
    for (var j = 0; j < arr.length; j++) {
        arr[j].forEach(function (currentValue) {
            if (currentValue % 2 !== 0) {
                res += 1
            }
        })
    }
    return res;

};
```