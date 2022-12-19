### 解题思路
奇偶括号嵌套((()()))
 [ 1, 2, 3, 3, 3, 3, 2, 1]
 [ A, B, A, A, A, A, B, A]

输出 [ 0, 1, 0, 0, 0, 0, 1, 0]

### 代码

```javascript
/**
 * @param {string} seq
 * @return {number[]}
 */
var maxDepthAfterSplit = function (seq) {
    seq.split("")
    let dep = 0;
    let arr = [];
    for (let i in seq) {
        let s = seq[i];
        if (s == "(") {
            dep++;
            arr.push(dep%2);
        } else {
            arr.push(dep%2);
            dep--;
        }
    }
    return arr;
    
};
// var maxDepthAfterSplit = function(seq) {
//     let dep = 0;
//     return seq.split("").map((value, index) => {
//         if (value === '(') {
//             ++dep;
//             return dep % 2;
//         } else {
//             let ans = dep % 2;
//             --dep;
//             return ans;
//         }
//     });
// };

```