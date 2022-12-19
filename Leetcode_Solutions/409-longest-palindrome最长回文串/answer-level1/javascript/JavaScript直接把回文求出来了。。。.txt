### 解题思路

直接把回文求出来了，显然是比较差的一种算法
下面注释的是大神的大牌大法，抽到一对就打出去

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */

var longestPalindrome = function(s) {
    const arr = s.split('')
    const temp = [], res = []
    for (let i = 0; i < arr.length; i++) {
        for (j = i + 1; j < arr.length; j++) {
            if (arr[i] === arr[j]) { // 相同的存起来
                temp.push(arr[i])
                temp.push(arr[j])
                arr.splice(j, 1) //先去掉j，先去i的话j就不对了
                arr.splice(i, 1)
                i-- // 回头
                break
            }
        }
    }
    let mid = temp.length / 2 
    for (let i = 0; i < temp.length; i += 2) { // 从中心开始堆叠
        res.push(temp[i])
        res.unshift(temp[i + 1])
    }
    if (arr.length > 0) { // 如果还有得多随便拿个插在中间
        res.splice(mid, 0, arr[0])
    }
    return res.length
};



// var longestPalindrome = function(s) {
//     const temp = new Set()
//     let sum = 0
//     s.split('').forEach(item => { // 利用Set，2个成对就删除
//         if (temp.has(item)) {
//             temp.delete(item)
//             sum += 2
//         } else {
//             temp.add(item)
//         }
//     })
//     sum = temp.size > 0 ? sum + 1 : sum
//     return sum
// };
```