### 解题思路

j / 10 >> 0 就是每次删掉最后一个数
例如：1234 -> 123 -> 12 -> 1 -> 0
j % 10 就是每次取最后一个
例如: 1234 -> 4
然后不符合条件的就break掉，这样速度快


### 更新
今天偶然一跑，居然是双100%，果然是运气游戏。

### 代码

```javascript
/**
 * @param {number} left
 * @param {number} right
 * @return {number[]}
 * 98.51%
 * 93.14%
 */
var selfDividingNumbers = function (left, right) {
    let ans = [];
    for (let i = left; i <= right; i++) {
        let flag = true;
        for (let j = i; j > 0; j = j / 10 >> 0) {
            let n = j % 10;
            if (!(i % n === 0 && n !== 0)) {
                flag = false;
                break;
            }
        }
        if(flag) ans.push(i);
    }
    return ans;
};

// 解法2
// var selfDividingNumbers = function (left, right) {
//     let ans = [];
//     for (let i = left; i <= right; i++) {
//         const some = i.toString().split('').some((item) => {
//             return !(i % item === 0 && item !== 0);
//         });
//         if (!some) ans.push(i);
//     }
//     return ans;
// };
```