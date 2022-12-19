### 解题思路
不依赖reverse(), 最快98% 内存 35.1

### 代码

```javascript
/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var flipAndInvertImage = function (A) {
    for (let i = 0; i < A.length; i++) {
        let len = A[i].length - 1
        // len >> 1 跟 parseInt(len / 2)一个效果
        for (let j = len >> 1; j >= 0; j--) {
            let left = 1 ^ A[i][len - j];
            let right = 1 ^ A[i][j];
            A[i][len - j] = right;
            A[i][j] = left;
            // 这种是解构写法，但实际测试出来内存大于上面的。装逼必备
            // [A[i][len - j], A[i][j]] = [1 ^ A[i][j], 1 ^ A[i][len - j]]
        }
    }
    return A;
};

// 第二种写法
// var flipAndInvertImage = function (A) {
//     let ans = [];
//     for (let i = 0; i < A.length; i++) {
//         let arr = [];
//         let len = A[i].length - 1
//         for (let j = len >> 1; j >= 0; j--) {
//             arr[j] = +!A[i][j]
//             arr[len - j] = +!A[i][len - j];
//             arr.push(1 ^ A[i][j]);
//         }
//         ans.push(arr);
//     }
//     return ans;
// };
```